#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	**ft_split(char *str)
{
	char **split = (char **)malloc(1000);
	int i = 0;
	int j = 0;
	int k = 0;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		split[k] = malloc(1000);
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0' && str[i] != '\n')
		{
			split[k][j] = str[i];
			i++;
			j++;
		}
		split[k][j] = '\0';
		if (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\0')
			k++;
		j = 0;
	}
	split[k] = NULL;
	return (split);
}

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write (1,&str[i],1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char **split;
	int i = 1;

	if(argc >= 2)
	{
		split = ft_split(argv[1]);
		while (split[i])
		{
			ft_putstr(split[i]);
			write(1," ",1);
			i++;
		}
		ft_putstr(split[0]);
	}
	printf("\n");
}
