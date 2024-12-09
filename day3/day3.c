#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define PREFIX_SIZE 4

int	main(int argc, char **argv)
{
	unsigned int	i;
	unsigned int	nb1 = 0;
	unsigned int	nb2 = 0;
	unsigned long	sum = 0;
	char			*data;
	const char		*prefix = "mul(";

	if (argc != 2)
		return (-1);
	data = argv[1];
	while (*data)
	{
		i = 0;
		while (*data && *data == prefix[i])
		{
			printf("Prefix %d\n", i);
			if (i == PREFIX_SIZE - 1)
			{
				data++;
				nb1 = atoi(data);
				printf("Set nb1 to %d!\n", nb1);
				while (isdigit(*data))
					data++;
				if (*(data++) != ',')
					break ;
				nb2 = atoi(data);
				printf("Set nb2 to %d!\n", nb2);

				while (isdigit(*data))
					data++;
				if (*data == ')')
					sum += nb1 * nb2;
				
				break ;
			}
			data++;
			i++;
		}
		data++;
	}
	printf("Total sum calculated was %lu\n", sum);
}
