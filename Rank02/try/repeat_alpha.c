#include <unistd.h>

void    ft_putchar_n(char c, int n)
{
    int i = 0;

    while(i <= n)
    {
        write(1, &c,1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 0;

    if(argc == 2)
    {
        while(argv[1][i])
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
               ft_putchar_n(argv[1][i], argv[1][i] - 'a'); 
            else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                ft_putchar_n(argv[1][i], argv[1][i] -'A');
            else
                write(1, &argv[1][i],1);
            i++;
        }
    }
    write(1,"\n",1);
    return (0);
}
