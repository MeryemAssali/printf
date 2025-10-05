/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:12:47 by mel-assa          #+#    #+#             */
/*   Updated: 2025/08/31 22:07:07 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*stn;

	stn = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (stn[i] == (unsigned char)c)
		{
			return ((void *)&stn[i]);
		}
		i++;
	}
	return (NULL);
}
