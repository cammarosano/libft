/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:46:15 by rcammaro          #+#    #+#             */
/*   Updated: 2020/12/07 21:51:23 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	load_buffer(int fd, char *buffer)
{
	ssize_t ret;

	if ((ret = read(fd, buffer, BUFFER_SIZE)) == -1)
		return (0);
	if (ret == 0)
		buffer[0] = -1;
	else
		buffer[ret] = '\0';
	return (1);
}

int	buffer_to_line(char *buffer, char **line)
{
	size_t	len;
	size_t	i;
	char	stop;

	len = line_len(buffer);
	if (!(*line = malloc(sizeof(char) * (len + 1))))
		return (-1);
	i = 0;
	while (i < len)
	{
		(*line)[i] = buffer[i];
		i++;
	}
	(*line)[i] = '\0';
	stop = buffer[i];
	mem_shift(buffer, i);
	if (stop == '\n')
		return (1);
	if (stop == -1)
		return (0);
	return (2);
}

int	get_next_line(int fd, char **line)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	int			ret;
	char		*temp;

	if (!line || (*line = NULL) || BUFFER_SIZE < 1 || fd < 0 || fd >= FD_MAX)
		return (-1);
	if (!buffer[fd][0] && !load_buffer(fd, buffer[fd]))
		return (-1);
	ret = buffer_to_line(buffer[fd], line);
	while (ret > 1)
	{
		if (!load_buffer(fd, buffer[fd]))
			return (free_set_null(line));
		temp = *line;
		if ((ret = buffer_to_line(buffer[fd], line)) == -1)
			return (free_set_null(&temp));
		if (!(*line = join(temp, *line)))
			return (-1);
	}
	return (ret);
}
