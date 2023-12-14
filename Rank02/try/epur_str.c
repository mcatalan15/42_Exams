#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
    write(1,&c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;
    int flag = 0;

    if (argc == 2)
    {
        while(argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while(argv[1][i])
        {
            if (argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1;    
            if (argv[1][i] != ' ' && argv[1][i] != '\t')
            {

                if (flag)
                    ft_putchar(' ');
                flag = 0;
                ft_putchar(argv[1][i]);
            }
            i++;
        }
    }
    write(1, "\n",1);
}
