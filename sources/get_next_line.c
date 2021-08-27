#include "../includes/get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			count_bytes;
	static char	*reminder = NULL;
	char		*temp;

	temp = NULL;
	count_bytes = 1;
	if (ft_first_step(fd, line, &reminder))
		return (-1);
	while (!ft_strchr(reminder, '\n') && (count_bytes > 0))
		ft_read_from_fd(&count_bytes, fd, &reminder);
	if (count_bytes == 0)
	{
		*line = ft_strdup(reminder);
		return (free_rem(&reminder, 0));
	}
	else if (count_bytes > 0)
	{
		*line = ft_substr(reminder, 0, (ft_strchr(reminder, '\n') - reminder));
		temp = ft_strdup(reminder + ft_strlen(*line) + 1);
		free(reminder);
		reminder = temp;
		return (1);
	}
	else
		return (free_rem(&reminder, -1));
}

int	ft_first_step(int	fd, char **line, char **reminder)
{
	if (fd < 0 || !line)
		return (1);
	if (NULL == *reminder)
	{
		*reminder = malloc(sizeof(char) * 1);
		if (NULL == *reminder)
			return (1);
		*reminder[0] = 0;
	}
	return (0);
}

void	ft_read_from_fd(int *count_bytes, int fd, char **reminder)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	temp = NULL;
	*count_bytes = read(fd, buf, BUFFER_SIZE);
	buf[*count_bytes] = '\0';
	temp = ft_strjoin(*reminder, buf);
	free(*reminder);
	*reminder = temp;
}

int	free_rem(char **reminder, int res)
{
	free(*reminder);
	*reminder = NULL;
	return (res);
}
