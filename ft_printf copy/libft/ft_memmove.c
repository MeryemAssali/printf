/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:16:00 by mel-assa          #+#    #+#             */
/*   Updated: 2025/09/07 23:18:07 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == src || n == 0)
		return (dst);
	if ((char *)dst > (const char *)src)
	{
		i = n - 1;
		while (i > 0)
		{
			((char *)dst)[i] = ((const char *)src)[i];
			i--;
		}
		((char *)dst)[i] = ((const char *)src)[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dst)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dst);
}
