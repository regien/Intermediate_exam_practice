#include <stdio.h>
#include <stdlib.h>

int		is_anagram(char *a, char *b)
{
	int		hash[255] = { 0 };
	int		i = 0;

	for (i = 0; a[i]; ++i)
		hash[(unsigned int)a[i]] += 1;
	for (i = 0; b[i]; ++i)
		hash[(unsigned int)b[i]] -= 1;
	for (i = 0; i < 255; ++i)
		if (hash[i] != 0)
			return (0);
	return (1);
}

/*
int		main(void)
{
	char a[] = "abcdef";
	char b[] = "fabcde";
	char p[] = "abca";
	char l[] = "bcab";


	printf("should be 1 = |%d|\n", is_anagram(a, b));
	printf("should be 0 = |%d|\n", is_anagram(p, l));
}*/
