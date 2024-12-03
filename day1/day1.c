#include <stdlib.h>
#include <stdio.h>

int	*parse_first_list(char *input)
{
	int	*first_list = calloc(sizeof(int), 1000);
	int	i = 0;

	if (!first_list)
		return (NULL);
	while (i < 1000)
	{
		first_list[i] = atoi(input);
		while (*input != '\n' || *input != '\0')
			printf("%c", *(input++));
		input++;
		printf("%d\n", i);
		i++;
	}
	return (first_list);
}

int	main(int argc, char **argv)
{
	int	*first_list;
	int	*second_list;
	int	total_sum = 0;

	if (argc != 2)
		return (-1);

	first_list = parse_first_list(argv[1]);
	for	(int i = 0; i < 1000; i++)
		printf("%d\n", first_list[i]);

	// Parse input
	//
	// Make the pairs
	//
	// Count the differences

	printf("Total difference between the lists is : %d\n", total_sum);

	return (0);
}
