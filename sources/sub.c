#include "../includes/fdf.h"

t_point	create_point(int x, int y)
{
	t_point	res;

	res.x = x;
	res.y = y;
	return (res);
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
