#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int		first = 0;
	int		i = 0;
	int		j = 0;


	while (i < na && j < nb)
	{
		if (a[i] > b[j])
			j++;
		else if (a[i] < b[j])
			i++;
		else if (a[i] == b[j])
		{
			if (first != 0)
				printf(" ");
			else
				first = 1;
			printf("%d", a[i]);
			i++;
			j++;
		}
	}
	printf("\n");
}

/*
int main(void)
{
	int		a[4] = {1, 2, 10, 15};
	int		b[4] = {2, 20, 40, 70};
	int		first[11] = {-5, 2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
	int		second[8] = {2, 4, 5, 6, 7, 10, 40, 70};
	int		third[3] = {100, 200, 300};
	int		s_third[4] = {1, 2, 3, 4};


	print_doublon(a, 4, b, 4);
	print_doublon(first, 11, second, 8);
	print_doublon(third, 3, s_third, 4);
}
*/
