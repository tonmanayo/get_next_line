/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 09:47:27 by tmack             #+#    #+#             */
/*   Updated: 2016/12/06 15:35:03 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/stat.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# define BUFF_SIZE 9999
# define ERROR -1

int		get_next_line(const int fd, char **line);
int		loop(char **store, int fd, int ret, char **str_end);
int		fd_store(int const fd, char **store);

#endif
