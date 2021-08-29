#include "../includes/fdf.h"

void	create_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

float	maximum(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	modulo(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * cos(0.8) - z;
}
