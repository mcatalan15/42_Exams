#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(char *src)
{
    char *strcpy;
    int i = 0;
    int len = 0;

    while(str[len])
        len++;
    strcpy = malloc(sizeof(*strcpy) * (len + 1));
    if (strcpy != NULL)
    {
        while(src[i])
        {
            strcpy[i] = src[i];
            i++;
        }
        strcpy[i] = '\0';
    }
    return (strcpy);
}
