#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i = 0;
    if(argc == 4 && argv[2][1] == '\0')
    {
        if (argv[2][0] == '*')
            printf("%d",(atoi(argv[1]) * atoi(argv[3])));
        else if (argv[2][0] == '+')
            printf("%d",(atoi(argv[1]) + atoi(argv[3])));
        else if (argv[2][0] == '-')
            printf("%d",(atoi(argv[1]) - atoi(argv[3])));
        else if (argv[2][0] == '/')
            printf("%d",(atoi(argv[1]) / atoi(argv[3])));
        else if (argv[2][0] == '%')
            printf("%d",(atoi(argv[1]) % atoi(argv[3])));
    }
    printf("\n");
}
