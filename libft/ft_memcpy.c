/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:49:39 by tmack             #+#    #+#             */
/*   Updated: 2016/10/24 13:47:42 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *source, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		((char*)dest)[i] = ((char*)source)[i];
		i++;
	}
	((char*)dest)[i] = '\0';
	return (dest);
}
