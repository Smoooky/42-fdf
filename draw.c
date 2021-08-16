#include "fdf.h"
#include <math.h>

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

float	isox(float x, float y)
{
	x = (x - y) * cos(0.8);
	return (x);
}

float	isoy(float x, float y, int z)
{
	y = (x + y) * sin(0.8) - z;
	return (y);
}

void	bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float	x_step;
	float	y_step;
	int 	max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	x_step = x1 - x;
	y_step = y1 - y;

//	x = isox(x, y);
//	y = isoy(x, y, z);
//	x1 = isox(x1, y1);
//	y1 = isoy(x1, y1, z1);
//
//
//	x += 150;
//	y += 150;
//	x1 += 150;
//	y1 += 150;

	max = MAX(MOD(x_step), MOD(y_step));
	x_step = x_step / max;
	y_step = y_step / max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_p, data->win_p, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void  draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}