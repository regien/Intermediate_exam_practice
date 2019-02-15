#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	swap(int *x, int *y)
{
	int		temp = *x;

	*x = *y;
	*y = temp;
}

int		factorial(int n)
{
	int	result = 1;

	if (n < 1)
		return (0);
	for (int i = 1; i < n; i++)
		result *= (i + 1);
	return (result);
}

int		permute(int **load, int *arr, int *i, int left, int right)
{
	int		*copy = memcpy(copy, arr, right + 1);


	if (left == right)
	{
		load[*i] = copy;
		*i = *i + 1;
	}
	else
	{
		for (i = left; i <= r; ++i)
		{
			swap(copy[left], copy[i]);
			permute(load, copy, i, left + 1, right);
			swap(copy[left], copy[i]);
		}
	}
}

int    **range_comb(int n);
{
	if (n < 1)
		return (NULL);

	// exact range of the list and permutations
	printf("factorial number = |%d|\n", factorial(n));
	int		**range = malloc(sizeof(int*) * factorial(n));
	int		*vaina = malloc(sizeof(int) * n);
	int		i = 0; // iterator
	int		size = 0;

	for (size = 0; size < n; size++)
		vaina[size] = size;
	permute(range, vaina, &i, 0, size - 1);
}


int			main(void)
{
	int		n = 2;
	int		**holder = range_comb(n);
	int		size = factorial(n);

	for (int i = 0; i < size; i++)
	{
		printf("index %d\n", i);
		for (int e = 0; e < n; ++e)
			printf("");
	}
}
