/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:21:12 by mel-assa          #+#    #+#             */
/*   Updated: 2025/10/05 17:22:18 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
#include "../libft/libft.h"

int ft_printf(const char *fmt, ...)
{
	int cnt = 0;
	int i = 0;

	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			cnt++;
			write(1, &fmt[i++], 1);
		}
		else
		{
			if (fmt[i+1] == '%')
			{
				write(1, "%", 1);
				i++;
				cnt++;
			}
			i++;
		}
	}
	return (cnt);
}
# include <stdio.h>
int main()
{
	printf("%d", ft_printf("100%% done\n"));
}