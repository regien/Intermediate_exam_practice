#include "t_point.h"

/*
** They are printing the 2D with an extra space so you
** didn't have to do the stupid math
** you have both solutions in the commented and uncomented versions
*/


void	mod_point(t_point *value, int x, int y)
{
	value->x = x;
	value->y = y;
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	t_point			holder;

//	printf("word = |%c|\n", tab[(begin.y) - 1][(begin.x + (begin.x - 1)) - 1]);
//	printf("printing x = |%d| and y = |%d|\n", begin.x, begin.y);
	if (begin.x > 0 && begin.x <= size.x && begin.y > 0 && begin.y <= size.y)
	{
//		printf("entering\n");
//		if (tab[(begin.y) - 1][(begin.x + (begin.x - 1)) - 1] == '0')
		if (tab[begin.y - 1][begin.x - 1] == '0')
		{
//			tab[(begin.y) - 1][(begin.x + (begin.x - 1)) - 1] = 'F';
			tab[begin.y - 1][begin.x - 1] = 'F';
			// begin recursive stuff
			mod_point(&holder, begin.x, begin.y - 1); // top
			flood_fill(tab, size, holder);
			mod_point(&holder, begin.x, begin.y + 1); // bot
			flood_fill(tab, size, holder);
			mod_point(&holder, begin.x - 1, begin.y); // left
			flood_fill(tab, size, holder);
			mod_point(&holder, begin.x + 1, begin.y); // right
			flood_fill(tab, size, holder);
		}
	}
}

/*
char	**make_area(char *zone[])
{
	int		x = -1;
	int		y = -1;
	char	**remainder = NULL;

	while (zone[++y])
		;
	while (zone[0][++x])
		;
	printf("printing value of y = |%d|\n", y);
	printf("printing value of x = |%d|\n", x);

	remainder = malloc(sizeof(char*) * y);
	for (int i = 0; i < y; ++i)
		remainder[i] = malloc((sizeof(char) * x) + 1);
	remainder[y] = NULL;
	for (int i = 0; i < y; ++i)
	{
		for (int e = 0; e < x; ++e)
			remainder[i][e] = zone[i][e];
		remainder[i][x] = '\0';
	}

	printf("merely testin -> zone\n");
	for (int i = 0; i < y ; ++i)
		printf("%s\n", zone[i]);
	printf("merely testin -> remainder\n");
	for (int i = 0; i < y ; ++i)
		printf("%s\n", remainder[i]);
	return(remainder);
}

void	print_tab(char **area)
{
	printf("intializing print_tab\n");
	for (int i = 0; area[i] ; ++i)
		printf("%s\n", area[i]);
}

int		main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};

	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
//	putc('\n');
	printf("\n");
	print_tab(area);
	return (0);
}
*/
