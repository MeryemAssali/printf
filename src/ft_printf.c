/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:21:12 by mel-assa          #+#    #+#             */
/*   Updated: 2025/10/11 19:13:52 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
#include "../libft/libft.h"

int ft_printf(const char *fmt, ...)
{
	va_list args; // the cursor that moves throught the arguements (declare the list)
	va_start (args, fmt); // Start right after the fixed arguement (fmt string in this case)
	int cnt;
	int i;

	cnt = 0;
	i = 0;
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
	va_end(args); // End trasversal
	return (cnt);
}
# include <stdio.h>
int main()
{
	printf("%d", ft_printf("100%% done\n"));
}