#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		count_islands(char *str)
{
	int		count = 0;
	int		i = 0;

	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
				i++;
			count++;
		}
		while(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
	}
	return (count);
}

void	fill_the_thing(char *str)

int main(int argc, char **argv)
{
	int		count = 0;
	int		*len = NULL;
	char	**arr = NULL;

	if (argc != 2)
		write(1, "\n", 1);
	else {
		count = count_islands(argv[1]);
		printf("count = |%d|\n", count);
		if (count <= 0)
			return (0);
		len = malloc(sizeof(int) * count);
		arr = malloc(sizeof(char*) * count);
		while ()
	}
	return (0);
}
