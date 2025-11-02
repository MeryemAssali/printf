/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:50:02 by mel-assa          #+#    #+#             */
/*   Updated: 2025/11/02 18:20:02 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>

static int dig_cnt(unsigned int n)
{
	int digcnt;
	
	digcnt = 1;
	while (n / 10)
	{
		digcnt++;
		n /= 10;
	}
	return (digcnt);
}
static char *ft_utoa (unsigned int n)
{
	char *stn;
	int diglen;

	diglen = dig_cnt(n);
	stn = malloc(diglen + 1);
	if (!stn)
		return (NULL);
	stn[diglen] = '\0';
	while (diglen--)
	{
		stn[diglen] = (n % 10) + '0';
		n /= 10;
	}
	return (stn);
}
int ft_handle_u(va_list *args)
{
	char *unsint;
	int	len;

	unsint = ft_utoa(va_arg(*args, unsigned int));
	if (!unsint)
		return (0);
	len = ft_strlen(unsint);
	write (1, unsint, len);
	free(unsint);
	return (len);
} 