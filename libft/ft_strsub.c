/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 16:07:23 by tmack             #+#    #+#             */
/*   Updated: 2016/08/19 12:03:09 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub(char const *source, size_t start, size_t len)
{
	char		*substring;

	substring = ft_strnew(len + 1);
	if (!substring)
		return (NULL);
	ft_memcpy(substring, &source[start], len);
	return (substring);
}
