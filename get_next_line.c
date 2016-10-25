/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 08:42:33 by tmack             #+#    #+#             */
/*   Updated: 2016/10/25 11:19:50 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer(int const fd, char *string, int *rd_byte)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	*rd_byte = read(fd, tmp, BUFF_SIZE);
	tmp[*rd_byte] = '\0';
	string = ft_strjoin(string, tmp);
	free(tmp);
	return (string);
}

int		loop(char *buff, const int fd, char **line)
{
	int		ret;
	char	*str;

	str = NULL;
	ret = 1;
	while (ret > 0)
	{
		if ((str = ft_strchr(buff, '\n')) != 0)
		{
			*str = '\0';
			if (line != NULL)
				free(*line);
			*line = ft_strdup(buff);
			ft_memmove(buff, str + 1, ft_strlen(str + 1) + 1);
			free(buff);
			free(*line);
			return (1);
		}
		else
			*line = ft_strdup(buff);
		buff = buffer(fd, buff, &ret);
	}
	ft_memdel((void **)&str);
	ft_memdel((void **)&buff);
	return (ret);
}

int		get_next_line(int const fd, char **line)
{
	static char		*buff = "";
	int				ret;

	if (line == NULL || fd < 0)
		return (-1);
	if (buff == NULL)
		buff = ft_strnew(0);
	ret = loop(buff, fd, line);
	return (ret);
}
