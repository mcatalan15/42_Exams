#include <unistd.h> // For write

char *ft_strrev(char *str)
{
	int i = 0;
	char temp;
	int len = 0;

	while (str[len])
		len++;
	len--;
	while (i != len)
	{
		temp = str[len];
		str[len] = str[i];
		str[i] = temp;
		len--;
		i++;
	}
	return (str);
}