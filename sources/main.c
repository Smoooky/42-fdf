#include "../includes/fdf.h"

int	deal_key(int key, void *data)
{
	(void)data;
	if (key == 53)
		exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		ft_printf("Wrong number of parameters\n");
		exit(0);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->mlx_p = mlx_init();
	data->win_p = mlx_new_window(data->mlx_p, 1000, 1000, "t_fdf");
	data->zoom = 20;
	data->shift = 150;
	draw(data);
	mlx_key_hook(data->win_p, deal_key, data);
	mlx_loop(data->mlx_p);
}
