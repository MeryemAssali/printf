/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:48:26 by mel-assa          #+#    #+#             */
/*   Updated: 2025/11/02 19:50:52 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>

static int hex_digcnt(unsigned int n)
{
	int xdiglen;

	xdiglen = 1;
	while (n / 16)
	{
		n /= 16;
		xdiglen++;
	}
	return (xdiglen);
}
static char *ft_itoax (unsigned int n, int lowcase)
{
	char *hexa;
	const char *hex_rep;
	int digcnt;
	
	if (lowcase == 0)
		hex_rep = "0123456789abcdef";
	else
		hex_rep = "0123456789ABCDEF";
	digcnt = hex_digcnt(n);
	hexa = malloc(digcnt + 1);
	if (!hexa)
		return (0);
	hexa[digcnt] = '\0';
	while (digcnt--)
	{
		hexa[digcnt] = hex_rep[n % 16];
		n /= 16;
	}
	return (hexa);
}
static int handle_x(va_list *args)
{
	char *hex;
	int len;

	hex = ft_itoax(va_arg(*args, unsigned int), 0);
	if (!hex)
		return (0);
	len = ft_strlen(hex);
	write (1, hex, len);
	free (hex);
	return (len);
}
static int handle_X(va_list *args)
{
	int len;
	char *hex;

	hex = ft_itoax(va_arg(*args, unsigned int), 1);
	if (!hex)
		return (0);
	len = ft_strlen(hex);
	write (1, hex, len);
	free (hex);
	return (len);
}