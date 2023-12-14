#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi(const char *str)
{
    int i = 0;
    int neg = 0;
    int res = 0;

    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = (str[i] - '0') + (res * 10);
        i++;
    }
    return (res * neg);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        printf("%d",ft_atoi(argv[1]));
}
