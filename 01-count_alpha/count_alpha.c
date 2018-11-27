#include <stdio.h>
#include <unistd.h>

void	print_alpha(char *str, char c, int *first)
{
	int		i = -1;
	int		count = 0;

	while(str[++i])
	{
		if (c == str[i] || (c - 32) == str[i])
		{
			count++;
			str[i] = ' ';
		}
	}
	if (*first == 0)
		*first += 1;
	else
		printf(", ");
	printf("%d%c", count, c);
}

int		main(int argc, char **argv)
{
	int		first = 0;

	if (argc != 2)
		printf("\n");
	else
	{
		for(int i = 0; argv[1][i]; ++i)
		{
			if ((argv[1][i] >= 65 && argv[1][i] <= 90 ) || (argv[1][i] >= 97 && argv[1][i] <= 122))
				print_alpha(argv[1], (argv[1][i] | 32), &first);
		}
		printf("\n");
	}
	return (0);
}
