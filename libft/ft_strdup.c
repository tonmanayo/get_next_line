/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 16:00:33 by tmack             #+#    #+#             */
/*   Updated: 2016/11/07 08:28:35 by tmack            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *source)
{
	char	*new;

	new = NULL;
	new = malloc(ft_strlen(source) + 1);
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, source);
	return (new);
}
