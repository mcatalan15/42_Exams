#include <unistd.h>

int is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

void last_word(char *str)
{
	int i = 0;
	int last_word_start = -1;

	while (str[i])
	{
		if (!is_whitespace(str[i]))
		{
			last_word_start = i;
			while (str[i] && !is_whitespace(str[i]))
				i++;
		}
		else
		{
			i++;
		}
	}

	if (last_word_start != -1)
	{
		while (str[last_word_start] && !is_whitespace(str[last_word_start]))
		{
			write(1, &str[last_word_start], 1);
			last_word_start++;
		}
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		last_word(argv[1]);
	}
	else
	{
		write(1, "\n", 1);
	}
	return 0;
}
