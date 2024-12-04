#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	max(int *numbers)
{
	int	i = 0;
	int	max;

	max = numbers[i++];
	while (i < 1000)
	{
		if (numbers[i] > max)
			max = numbers[i];
		i++;
	}
	return (max);
}

int	*parse_first_list(char *input)
{
	int	*first_list = calloc(sizeof(int), 1000);
	int	i = 0;

	if (!first_list)
		return (NULL);
	while (i < 1000) 
	{
		first_list[i++] = atoi(input);
		while (*input && *input != '\n')
			input++;
		input++;
	}
	return (first_list);
}

int	*parse_second_list(char *input)
{
	int	*second_list = calloc(sizeof(int), 1000);
	int	i = 0;

	if (!second_list)
		return (NULL);
	while (i < 1000) 
	{
		while (isdigit(*input))
			input++;
		while (*input == ' ')
			input++;
		second_list[i++] = atoi(input);
		while (*input && *input != '\n')
			input++;
		input++;
	}
	return (second_list);
}

int	main(int argc, char **argv)
{
	int	*first_list;
	int	*second_list;
	int	total_sum = 0;
	int	first_threshold = 0;
	int	second_threshold = 0;
	int	first_min = 0;
	int	second_min = 0;
	int	first_max;
	int	second_max;

	if (argc != 2)
		return (-1);

	first_list = parse_first_list(argv[1]);
	second_list = parse_second_list(argv[1]);

	first_threshold = 0;
	first_max = max(first_list);

	second_threshold = 0;
	second_max = max(second_list);

	for (int i = 0; i < 1000; i++)
	{
		first_min = first_max;
		second_min = second_max;
		for (int j = 0; j < 1000; j++)
		{
			if (first_min > first_list[j] && first_list[j] > first_threshold)
				first_min = first_list[j];
		}
		for (int j = 0; j < 1000; j++)
		{
			if (second_min > second_list[j] && second_list[j] > second_threshold)
				second_min = second_list[j];
		}
		printf("%d\t%d\n", first_min, second_min);
		total_sum += abs(first_min - second_min);
		first_threshold = first_min;
		second_threshold = second_min;
	}
	printf("Total difference between the lists is : %d\n", total_sum);

	free(first_list);
	free(second_list);

	return (0);
}
