#include <stdio.h>
#include <stdlib.h>

int		find_pivot(int *arr, int n)
{
	int		sum = 0;
	int		leftsum = 0;

	for (int i = 0; i < n; ++i)
		sum += arr[i];
	for (int i = 0; i < n; ++i)
	{
		sum = sum - arr[i];
		if (leftsum == sum)
			return (i);
		leftsum += arr[i];
	}
	return (-1);
}

/*
int		main(void)
{
	int		vaina[] = {1, 2, 3, 4, 0, 6};
	int		segundo[] = {-5, 10, 2, 5};
	int		tercero[] = {1, 100, 0, 0, 1};
	int		cuarto[] = {7, 9, 8};
	int		quinto[] = {1, 2};

	printf("first example should be 3 = %d\n", find_pivot(vaina, 6));
	printf("second example should be 2 = %d\n", find_pivot(segundo, 4));
	printf("third example should be 1 = %d\n", find_pivot(tercero, 5));
	printf("fourth example should be -1 = %d\n", find_pivot(cuarto, 3));
	printf("fifth example should be -1 = %d\n", find_pivot(quinto, 2));
}
*/
