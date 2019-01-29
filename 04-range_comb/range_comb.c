#include <stdio.h>
#include <stdlib.h>

// string permutation
void	swap(char *x, char *y)
{
	char	temp = *x;

	*x = *y;
	*y = temp;
}

// basically str, beginning , end
void	permute(char *a, int left, int right)
{
	int		i;

	if (left == right)
		printf("%s\n", a);
	else
	{
		for (i = left; i <= right; ++i) {
			swap((a + left), (a + i));
			permute(a, left + 1, right);
			swap((a + left), (a + i)); // backtrack
		}
	}
}

int		main(void)
{
	permute("ABC", 0, 2);
}
