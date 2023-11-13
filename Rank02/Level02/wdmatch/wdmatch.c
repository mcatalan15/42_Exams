#include <unistd.h> // For write

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int ft_strlen(char *str)
{
	int size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

void ft_wd_match(char *first, char *second)
{
	int idx_first;
	int idx_second;

	idx_first = 0;
	idx_second = 0;
	while (second[idx_second] != '\0')
	{
		if (first[idx_first] == second[idx_second])
			idx_first++;
		idx_second++;
	}
	if (idx_first == ft_strlen(first))
		ft_putstr(first);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_wd_match(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}