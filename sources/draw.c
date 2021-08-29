#include "../includes/fdf.h"

void	add_shift(t_point *a, t_point *b, t_fdf *data)
{
	a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;
}

void	add_zoom(t_point *a, t_point *b, t_fdf *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	b->x *= data->zoom;
	b->y *= data->zoom;
}

void	bresenham_sub(t_point a, t_point b, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = maximum(modulo(x_step), modulo(y_step));
	x_step = x_step / max;
	y_step = y_step / max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_p, data->win_p, a.x, a.y, data->color);
		a.x += x_step;
		a.y += y_step;
	}
}

void	bresenham(t_point a, t_point b, t_fdf *data)
{
	int		z;
	int		z1;

	z = data->z_matrix[(int)a.y][(int)a.x];
	z1 = data->z_matrix[(int)b.y][(int)b.x];
	data->color = 0xffffff;
	if (z || z1)
		data->color = 0xe80c0c;
	add_zoom(&a, &b, data);
	isometric(&a.x, &a.y, z);
	isometric(&b.x, &b.y, z1);
	add_shift(&a, &b, data);
	bresenham_sub(a, b, data);
}

void	draw(t_fdf *data)
{
	int		x;
	int		y;
	t_point	a;
	t_point	b;
	t_point	c;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			create_point(&a, x, y);
			create_point(&b, x + 1, y);
			create_point(&c, x, y + 1);
			if (x < data->width - 1)
				bresenham(a, b, data);
			if (y < data->height - 1)
				bresenham(a, c, data);
			x++;
		}
		y++;
	}
}
