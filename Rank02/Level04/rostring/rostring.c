#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int z;

	if (ac > 1)
	{
		i = 0;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		z = i;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
			i++;
		while (av[1][i])
		{
			if (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t') && (av[1][i - 1] == ' ' || av[1][i - 1] == '\t'))
			{
				while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
				{
					write(1, &av[1][i], 1);
					i++;
				}
				write(1, " ", 1);
			}
			i++;
		}
		while (av[1][z] && (av[1][z] != ' ' && av[1][z] != '\t'))
		{
			write(1, &av[1][z], 1);
			z++;
		}
	}
	write(1, "\n", 1);
	return (0);
}



































































































int main (int ac, char **argv)
{
	int i = 0;
	int start = 0;

	if(ac > 1)
	{
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		start = i;
		while (argv[1][i] && (argv[1][i] != ' ' && argv[1][i] != '\t'))
			i++;
		while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			i++;
		while (argv[1][i])
		{
			if ((argv[1][i] == ' ' || argv[1][i] == '\t') && (argv[1][i - 1] != ' ' && argv[1][i - 1] != '\t'))
				write(1, &argv[1][i], 1);
			else if (argv[1][i] != ' ' && argv[1][i] != '\t')
				write(1, &argv[1][i], 1);
			i++;
		}
		i = start;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n",1);	
}