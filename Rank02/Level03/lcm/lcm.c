#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n = a > b ? a : b;

	if (a == 0 || b == 0)
		return (0);
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}
