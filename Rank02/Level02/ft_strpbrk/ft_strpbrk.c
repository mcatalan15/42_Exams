#include <stddef.h> // For NULL || (void *)0 || 0

char *ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}