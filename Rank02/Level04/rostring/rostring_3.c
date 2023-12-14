#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, int size)
{
	int i = 0;

	while (i < size && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	char	**result;
	int	wc = 0;
	int	start = 0;
	int i = 0;
	int k = 0;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			wc++;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	result = malloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			start = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		if (start < i)
		{
			result[k] = malloc(sizeof(char) * (i - start + 1));
			ft_strncpy(result[k], &str[start], (i - start));
			k++;
		}
	}
	result[k] = NULL;
	return (result);
}

void	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**split;
	int	i = 1;

	if (argc >= 2)
	{
		split = ft_split(argv[1]);
		while (split[i])
		{
			ft_putstr(split[i]);
			write(1, " ", 1);
			i++;
		}
		ft_putstr(split[0]);
	}
	write(1,"\n",1);
}
