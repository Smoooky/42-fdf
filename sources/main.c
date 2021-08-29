#include "../includes/fdf.h"

void	free_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
	free(data);
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 126 || key == 125 || key == 124 || key == 123)
	{
		mlx_clear_window(data->mlx_p, data->win_p);
		if (key == 125)
			data->shift_y += 10;
		else if (key == 124)
			data->shift_x += 10;
		else if (key == 126)
			data->shift_y -= 10;
		else
			data->shift_x -= 10;
		draw(data);
	}
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_p, data->win_p);
		free_matrix(data);
		sleep(17);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	data = NULL;
	if (argc != 2)
	{
		ft_printf("Wrong number of parameters\n");
		exit(0);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_p = mlx_init();
	data->win_p = mlx_new_window(data->mlx_p, 2000, 1000, "t_fdf");
	data->zoom = 20;
	data->shift_x = 600;
	data->shift_y = 300;
	draw(data);
	mlx_key_hook(data->win_p, deal_key, data);
	mlx_loop(data->mlx_p);
}
