#include "../includes/fdf.h"

void	check_fd(int fd)
{
	if (fd == -1)
	{
		ft_printf("Wrong file\n");
		exit(0);
	}
}

int	word_count(char *str)
{
	char	**splited;
	int		res;

	splited = ft_split(str, ' ');
	res = 0;
	while (splited[res] != NULL)
		res++;
	return (res);
}

t_fdf	*get_size(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		height;
	int		width;

	fd = open(file_name, O_RDONLY);
	check_fd(fd);
	height = 1;
	get_next_line(fd, &line);
	width = word_count(line);
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	data->width = width;
	data->height = height;
	return (data);
}

t_fdf	*fill_matrix(t_fdf *data, char *file_name)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
	char	**nums;

	i = 0;
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		nums = ft_split(line, ' ');
		j = 0;
		while (nums[j])
		{
			data->z_matrix[i][j] = ft_atoi(nums[j]);
			j++;
			free(nums[j]);
		}
		free(line);
		i++;
	}
	free(nums);
	close(fd);
	data->z_matrix[i] = NULL;
	return (data);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;

	data = get_size(file_name, data);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *) malloc(sizeof(int) *(data->width + 1));
	data = fill_matrix(data, file_name);
}
