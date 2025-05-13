#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int maxClients = 2000;
int client[2000] = {-1};
char *message[2000];
fd_set cur, cur_write, cur_read;

void exit_error(char *msg)
{
	write(2, msg, strlen(msg));
	exit(1);
}

void fatal_error()
{
	exit_error("Fatal error\n");
}

void send_message(int fd, char *str)
{
	for (int i = 0; i < maxClients; i++)
	{
		if (client[i] != -1 && i != fd && FD_ISSET(i, &cur_write))
			send(i, str, strlen(str), 0);
	}
}

int extract_message(char **buf, char **msg)
{
	char *new;
	int i = -1;

	*msg = 0;
	if (*buf == 0)
		return 0;
	while ((*buf)[++i])
	{
		if ((*buf)[i] == '\n')
		{
			new = calloc(sizeof(*new), strlen(*buf + i + 1) + 1);
			if (!new)
				return -1;
			strcpy(new, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = new;
			return 1;
		}
	}
	return 0;
}

char *str_join(char *buf, char *add)
{
	char *new;
	int len = (buf == 0 ? 0 : strlen(buf));

	new = calloc(sizeof(*new), len + strlen(add) + 1);
	if (!new)
		return NULL;
	new[0] = 0;
	if (buf)
		strcat(new, buf);
	free(buf);
	strcat(new, add);
	return new;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		exit_error("Wrong number of arguments\n");
	struct sockaddr_in servaddr;
	int sockfd;
	int max;
	int index = 0;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		fatal_error();

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1]));

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
		fatal_error();
	if (listen(sockfd, 128) != 0)
		fatal_error();

	FD_SET(sockfd, &cur);
	max = sockfd;

	while (1)
	{
		cur_read = cur_write = cur;
		if (select(max + 1, &cur_read, &cur_write, NULL, NULL) < 0)
			continue;
		for (int fd = 0; fd <= max; fd++)
		{
			if (FD_ISSET(fd, &cur_read))
			{
				if (fd == sockfd)
				{
					int newclient = accept(sockfd, NULL, NULL);
					char str[100];

					if (newclient <= 0)
						continue;

					client[newclient] = index++;
					message[newclient] = malloc(1);
					message[newclient][0] = 0;
					FD_SET(newclient, &cur);

					if (newclient > max)
						max = newclient;
					sprintf(str, "server: client %d just arrived\n", index - 1);
					send_message(newclient, str);
				}
				else
				{
					char buffer[4095];
					int lent = recv(fd, buffer, 4094, 0);

					if (lent <= 0)
					{
						char str[100];

						sprintf(str, "server: client %d just left\n", client[fd]);
						send_message(fd, str);

						client[fd] = -1;
						FD_CLR(fd, &cur);
						close(fd);
					}
					else
					{
						char *msg;

						buffer[lent] = 0;
						message[fd] = str_join(message[fd], buffer);

						while (extract_message(&message[fd], &msg))
						{
							char str[strlen(msg) + 100];

							sprintf(str, "client %d: %s", client[fd], msg);
							send_message(fd, str);
						}
					}
				}
			}
		}
	}
}