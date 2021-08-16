#include "fdf.h"

int deal_key(int key, void *data)
{
	printf("%d", key);
	return(0);
}

int main(int argc, char **argv)
{
	fdf *data;
	int i;
	int j;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_p = mlx_init();
	data->win_p = mlx_new_window(data->mlx_p, 1000, 1000, "FDF");
//	mlx_pixel_put(data->mlx_p, data->win_p, (int)x, (int)y, #color);
//	bresenham(10, 10, 600, 600, data);
	data->zoom = 20;
	draw(data);
	mlx_key_hook(data->win_p, deal_key, NULL);
	mlx_loop(data->mlx_p);
}