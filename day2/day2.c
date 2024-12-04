#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

int	**parse_input(char *input)
{
	int	**parsed_numbers = calloc(sizeof(int *), 1000);
	int	i;
	int	j;

	i = 0;
	// Need to allocate the int pointers as well
	while (*input)
	{
		j = 0;
		parsed_numbers[i][j] = atoi(input);
		while (*input && isdigit(*input))
		{
			write(1, input, 1);
			if (*input == '\n')
				i++;
			input++;
		}
		j++;
	}
	return (parsed_numbers);
}

int	main(int argc, char **argv)
{
	int	**numbers;

	if (argc != 2)
		return (-1);
	numbers = parse_input(argv[1]);
}
