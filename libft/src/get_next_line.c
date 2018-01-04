/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccharuel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:30:56 by ccharuel          #+#    #+#             */
/*   Updated: 2017/03/06 14:17:03 by ccharuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int					ft_result(char **line, char *buffer)
{
	char			*str;

	str = ft_strchr(buffer, '\n');
	if (str != NULL)
	{
		*str = '\0';
		*line = ft_strdup(buffer);
		ft_memmove(buffer, &str[1], ft_strlen(&str[1]) + 1);
		return (1);
	}
	if (ft_strlen(buffer) > 0)
	{
		*line = ft_strdup(buffer);
		*buffer = '\0';
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static char		*buffer[NB_FILES];
	char			buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (line == NULL || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strnew(0);
	while (!ft_strchr(buffer[fd], '\n'))
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			break ;
		buff[ret] = '\0';
		tmp = ft_strjoin(buffer[fd], buff);
		free(buffer[fd]);
		buffer[fd] = tmp;
	}
	return (ft_result(line, buffer[fd]));
}
