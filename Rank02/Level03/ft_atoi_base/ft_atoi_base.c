#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;

	if (*str == '-')
	{
		sign = -1;
		str++;
	}

	while (*str)
	{
		char currentChar = *str;

		if ((currentChar >= '0' && currentChar <= '9') ||
			(currentChar >= 'a' && currentChar <= 'f') ||
			(currentChar >= 'A' && currentChar <= 'F'))
		{

			int digitValue;

			if (currentChar >= '0' && currentChar <= '9')
			{
				digitValue = currentChar - '0';
			}
			else if (currentChar >= 'a' && currentChar <= 'f')
			{
				digitValue = 10 + currentChar - 'a';
			}
			else
			{
				digitValue = 10 + currentChar - 'A';
			}

			result = result * str_base + digitValue;
		}
		else
		{
			break;
		}

		str++;
	}

	return result * sign;
}

// int main()
// {
// 	const char *hexNumber = "16";
// 	int decimalNumber = ft_atoi_base(hexNumber, 1010);
// 	printf("Decimal equivalent of %s is: %d\n", hexNumber, decimalNumber);

// 	return 0;
// }
