#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ft_strncpy(char *dest, char *src, int size)
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

char **ft_split(char *str)
{
	char **result;
	int wordcounter = 0;
	int start = 0;
	int i = 0;
	int k = 0;

	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			wordcounter++;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	result = malloc(sizeof(char *) * (wordcounter + 1));
	i = 0;
	while (str[i])
	{
		start = -1;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			start = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		if (start < i && start != -1)
		{
			result[k] = malloc(sizeof(char) * (i - start + 1));
			ft_strncpy(result[k], &str[start], (i - start));
			k++;
		}
	}
	result[k] = NULL;
	return (result);
}
