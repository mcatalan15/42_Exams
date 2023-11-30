// #include <unistd.h> // For write // For write

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// void	print_bits(unsigned char octet)
// {
// 	int idx = 8;
// 	unsigned char	bit;

// 	while (idx >= 0)
// 	{
// 		bit = ((octet >> idx & 1) + '0');
// 		ft_putchar(bit);
// 		idx--;
// 	}
// }

unsigned char	reverse_bits(unsigned char octet)
{
	int i;
	unsigned char bit;

	i = 7;
	while (i >= 0)
	{
		bit = ((bit * 2) + (octet % 2));
		octet /= 2;
		i--;
	}
	return (bit);
}