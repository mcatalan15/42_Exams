#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_strchr(const char *s, int c)
{
    size_t i = 0;

    while(s[i])
    {
        if (s[i] == c)
            return ((char *)s);
        i++;
    }
    return (NULL);
}

char    *ft_strpbrk(const char *s1, const char *s2)
{
    while(*s1)
    {
        if (ft_strchr(s2, *s1))
            return ((char *)s1);
        s1++;
    }
    return (NULL);
}
