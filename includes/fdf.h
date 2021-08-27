#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	void	*mlx_p;
	void	*win_p;
}			t_fdf;

typedef struct s_point
{
	float	x;
	float	y;
}			t_point;

void	read_file(char *file_name, t_fdf *data);
void	bresenham(t_point a, t_point b, t_fdf *data);
void	draw(t_fdf *data);
t_point	create_point(int x, int y);
float	maximum(float a, float b);
float	modulo(float a);
void	isometric(float *x, float *y, int z);

#endif