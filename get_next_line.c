/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 07:08:36 by tmack             #+#    #+#             */
/*   Updated: 2016/12/06 15:54:31 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		fd_store(const int fd, char **store)
{
	char		*buff;
	int			nbr_bytes;
	char		*new_line;

	new_line = NULL;
	buff = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	nbr_bytes = read(fd, buff, BUFF_SIZE);
	if (nbr_bytes > 0)
	{
		new_line = ft_strjoin(*store, buff);
		if (!new_line)
			return (ERROR);
		*store = ft_strdup(new_line);
	}
	if (new_line != NULL)
		free(new_line);
	free(buff);
	return (nbr_bytes);
}

int		loop(char **store, int fd, int ret, char **str_end)
{
	while (!*str_end)
	{
		ret = fd_store(fd, store);
		if (ret == 0)
		{
			if ((*str_end = ft_strchr(*store, '\0')) == *store)
				return (0);
		}
		else if (ret < 0)
			return (ERROR);
		else
			*str_end = ft_strchr(*store, '\n');
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*store = NULL;
	char		*str_end;
	int			ret;

	ret = 0;
	if (!store && (store = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (ERROR);
	str_end = ft_strchr(store, '\n');
	if (loop(&store, fd, ret, &str_end) == 0)
		return (0);
	else if (loop(&store, fd, ret, &str_end) == ERROR)
		return (ERROR);
	*line = ft_strsub(store, 0, str_end - store);
	str_end = ft_strdup(str_end + 1);
	store = str_end;
	return (1);
}
