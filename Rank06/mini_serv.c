#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_CLIENTS 10000
#define MAX_BUFFER 4000000

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void fatal_error(char *msg)
{
	write(2,msg,strlen(msg));
	exit(1);
}

typedef struct s_client
{
	int id;
	char *buf;
} t_client;

int main(int argc, char **argv)
{
	t_client clients[MAX_CLIENTS];
	bzero(clients, sizeof(clients));
	char buffer[MAX_BUFFER];
	bzero(buffer,sizeof(buffer));
	int id = 0;
	if (argc!=2)
		fatal_error("Wrong number of arguments\n");
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1)
		fatal_error("Fatal error\n");
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1]));
  	if ((bind(serverSocket, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal_error("Fatal error\n");
	if (listen(serverSocket, 3001) != 0)
		fatal_error("Fatal error\n");
	fd_set currentSockets, readSockets, writeSockets;
	FD_ZERO(&currentSockets);
	FD_SET(serverSocket, &currentSockets);
	int max_socket = serverSocket;	
	while(1)
	{
		readSockets = currentSockets;
		writeSockets = currentSockets;
		if(select(max_socket + 1, &readSockets, &writeSockets, NULL, NULL) == -1)
			continue;
		for (int fd = 0; fd <= max_socket; fd++)
		{
			if (FD_ISSET(fd, &readSockets))
			{
				if (fd == serverSocket)
				{
					int clientSocket = accept(fd,0,0);
					if (clientSocket == -1)
						continue;
					if (clientSocket > max_socket)
						max_socket = clientSocket;
					clients[clientSocket].id = id++;
					clients[clientSocket].buf = 0;
					FD_SET(clientSocket, &currentSockets);
					char tmp[50];
					sprintf(tmp, "server: client %d just arrived\n", id - 1);
					for (int i = 0; i <= max_socket; i++)
						if (i != fd && FD_ISSET(i, &writeSockets))
							send(i,tmp,strlen(tmp),0);
				}
				else
				{
					bzero(buffer,sizeof(buffer));
					if (recv(fd,buffer,sizeof(buffer),0) <= 0)
					{
						close(fd);
						FD_CLR(fd, &currentSockets);
						char tmp[50];
						sprintf(tmp, "server: client %d just left\n", clients[fd].id);
						clients[fd].id = 0;
						if (clients[fd].buf)
						{
							free(clients[fd].buf);
							clients[fd].buf = 0;
						}
						for (int i = 0; i <= max_socket; i++)
							if (i != fd && FD_ISSET(i, &writeSockets))
								send(i,tmp,strlen(tmp),0);		
					}
					else
					{
						clients[fd].buf = str_join(clients[fd].buf,buffer);
						char tmp[50];
						sprintf(tmp, "client %d: ", clients[fd].id);
						char *msg;
						while(extract_message(&clients[fd].buf,&msg))
						{
							for (int i = 0; i <= max_socket; i++)
								if (i != fd && FD_ISSET(i, &writeSockets))
								{
									send(i,tmp,strlen(tmp),0);
									send(i,msg,strlen(msg),0);
								}
							free(msg);
						}
					}
				}
			}
		}
	}
}
