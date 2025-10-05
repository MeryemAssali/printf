/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:54:39 by mel-assa          #+#    #+#             */
/*   Updated: 2025/09/07 20:19:10 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	lendst;

	lendst = ft_strlen(dst);
	i = 0;
	if (lendst < dstsize)
	{
		while (src[i] && (i < dstsize - lendst - 1))
		{
			dst[lendst + i] = src[i];
			i++;
		}
		dst[lendst + i] = '\0';
		return (lendst + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
