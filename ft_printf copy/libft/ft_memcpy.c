/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:59:07 by mel-assa          #+#    #+#             */
/*   Updated: 2025/09/07 23:31:33 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr1;
	const char	*ptr;

	if (!src && !dst)
		return (NULL);
	ptr = (const char *)src;
	ptr1 = (char *)dst;
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char arr[20] = "abcdefg";
// 	char arr1[20] = "abcdefg";

// 	// Overlap case
// 	ft_memcpy(arr + 1, arr, 7);
// 	memmove(arr1 + 1, arr1, 7);

// 	printf("%s \n", arr);
// 	printf("%s", arr1);
// }