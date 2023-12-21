#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int *ft_range(int start, int end)
{
	int *range;
	int i = 0;

	if (start > end)
		range = malloc(sizeof(int) * (start - end) + 1);
	else
		range = malloc(sizeof(int) * (end - start) + 1);
	while (start != end)
	{
		range[i++] = start;
		start += (start > end) ? -1 : 1;
	}
	range[i] = start;
	return (range);
}

/*
int main(int argc, char **argv)
{
	int start;
	int end;
	int *range;
	int len = 4;

	if (argc == 3)
	{
		start = atoi(argv[1]);
		end = atoi(argv[2]);
		range = ft_range(start, end);

		int i = 0;
		while(i < len)
			printf("%d, ", range[i++]);
	}
}

With(1, 3) you will return an array containing 1, 2 and 3. 
With(-1, 2) you will return an array containing - 1, 0, 1 and 2.
With(0, 0) you will return an array containing 0.
With(0, -3) you will return an array containing 0, -1, -2 and -3.

*/