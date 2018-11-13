int		help_count_2(int n)
{
	int		i = 0;
	while (n > 0)
	{
		if (n % 10 == 2)
			++i;
		n /= 10;
	}
	return (i);
}

int		count_of_2(int n)
{
	int		i = 0;
	int		counter = 0;

	if (n <= 1)
		return (0);
	while(++i <= n)
		counter += help_count_2(i);
	return (counter);
}

/*
int main(void)
{
	printf("valor de pendejada %d  = %d\n", 25, count_of_2(25));
	printf("valor de pendejada %d  = %d\n", 1, count_of_2(1));
}
*/
