#ifndef FDF_H
#define FDF_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"
#include "printf/includes/ft_printf.h"
#include "minilibx_macos/mlx.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

typedef struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	void	*mlx_p;
	void	*win_p;
} 			fdf;

void	read_file(char *file_name, fdf *data);
void	bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf *data);

#endif