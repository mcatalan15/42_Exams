#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int res = 0;
	int neg = 1;

	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}

	while (str[i])
	{
		char c = str[i];

		if ((c >= '0' && c <= '9') ||
			(c >= 'a' && c <= 'f') ||
			(c >= 'A' && c <= 'F'))
		{

			int digitValue;

			if (c >= '0' && c <= '9')
				digitValue = c - '0';
			else if (c >= 'a' && c <= 'f')
				digitValue = 10 + c - 'a';
			else
				digitValue = 10 + c - 'A';
			res = res * str_base + digitValue;
		}
		else
			break ;
		i++;
	}
	return (res * neg);
}

// int main()
// {
// 	const char *hexNumber = "16";
// 	int decimalNumber = ft_atoi_base(hexNumber, 1010);
// 	printf("Decimal equivalent of %s is: %d\n", hexNumber, decimalNumber);

// 	return 0;
// }
