#ifndef T_POINT_FLOOD_FILL
# define T_POINT_FLOOD_FILL
# include <stdlib.h>
# include <stdio.h>
# include <string.h>



typedef struct 	s_point {
    int 		x;				// x : Width  | x-axis
    int 		y;				// y : Height | y-axis
} 				t_point;

void	mod_point(t_point *value, int x, int y);

#endif

