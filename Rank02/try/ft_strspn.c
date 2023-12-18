#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t  ft_strspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;

    while(s[i] != '\0')
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}
