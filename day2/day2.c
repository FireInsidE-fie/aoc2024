#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define INPUT_LINES 1000
#define MAX_LINE_LENGTH 10

int	**allocate_numbers(void)
{
	int	**numbers = calloc(sizeof(int *), INPUT_LINES);

	for (int i = 0; i < 1000; i++)
		numbers[i] = calloc(sizeof(int), MAX_LINE_LENGTH);
	return (numbers);
}

int	**parse_input(char *input)
{
	int	**parsed_numbers = allocate_numbers();
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*input)
	{
		parsed_numbers[i][j++] = atoi(input);
		while (isdigit(*input))
			input++;
		if (*(input++) == '\n')
		{
			i++;
			j = 0;
		}
	}
	return (parsed_numbers);
}

int	main(int argc, char **argv)
{
	int	**numbers;
	int	safe_sequences;
	int	movement; // 1 for increasing, -1 for decreasing
	int	i;
	int	j;

	if (argc != 2)
		return (-1);
	numbers = parse_input(argv[1]);
	i = 0;
	while (i < INPUT_LINES)
	{
		j = 0;
		while (j < MAX_LINE_LENGTH)
			printf("%d ", numbers[i][j++]);
		i++;
		printf("\n");
	}

	safe_sequences = 0;
	i = 0;
	while (i < INPUT_LINES)
	{
		j = 0;
		if (numbers[i][j] > numbers[i][j + 1])
			movement = -1;
		else if (numbers[i][j] < numbers[i][j + 1])
			movement = 1;
		else
		{
			i++;
			continue ;
		}
		while (j < MAX_LINE_LENGTH)
		{
			if (numbers[i][j + 1] == 0)
			{
				safe_sequences++;
				break ;
			}
			if (movement < 1)
			{
				if (numbers[i][j + 1] - numbers[i][j] > 3
						|| numbers[i][j + 1] - numbers[i][j] < 1)
					break ;
			}
			else if (movement > 1)
			{
				if (numbers[i][j] - numbers[i][j + 1] > 3
						|| numbers[i][j] - numbers[i][j + 1] < 1)
					break ;
			}
			j++;
		}
		i++;
	}

	printf("Total number of safe sequences : %d\n", safe_sequences);
}
