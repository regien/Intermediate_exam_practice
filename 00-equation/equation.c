#include <stdio.h>
#include <stdlib.h>

void		equation(int n)
{
	int		a = -1;
	int		b;
	int		c;

	while (++a < 10)
	{
		b = -1;
		while (++b < 10)
		{
			c = -1;
			while(++c < 10)
			{
				if (((a * 10) + b) + ((c * 10) + a) == n)
					printf("A = %d, B = %d, C = %d\n", a, b, c);
			}
		}
	}
}

/*
int			main(int ac, char **av)
{
	if (ac != 2)
		exit(0);
	else
		equation(atoi(av[1]));
}
*/
