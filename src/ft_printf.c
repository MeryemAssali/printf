/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:21:12 by mel-assa          #+#    #+#             */
/*   Updated: 2025/11/02 19:49:10 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int print_pct(void)
{
	write(1, "%", 1);
	return (1);
}
static int handle_c(va_list *args)
{
	char c;
	c = va_arg(*args, int);
	write (1, &c, 1);
	return (1);
}
static int handle_s (va_list *args)
{
	char *str;
	int len;

	str = va_arg (*args, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}
static int handle_d (va_list *args) // convert from int to char 
{
	char *nt;
	int len;

	nt = ft_itoa(va_arg(*args, int));
	len = ft_strlen(nt);
	write(1, nt, len);
	free(nt);
	return (len);
}

int ft_printf(const char *fmt, ...)
{
	va_list args;
	va_start (args, fmt);
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	while (fmt[i]) 
	{
		if (fmt[i] != '%')
		{
			write(1, &fmt[i++], 1);
			cnt++;
		}
		else if (fmt[++i])
		{
			if (fmt[i] == '%')
				cnt += print_pct();
			else if (fmt[i] == 'c')
				cnt += handle_c (&args);
			else if (fmt[i] == 's')
				cnt += handle_s(&args);
			else if (fmt[i] == 'd' || fmt[i] == 'i')
				cnt += handle_d (&args);
			else if (fmt[i] == 'u')
				cnt += ft_handle_u (&args);
			else if (fmt[i] == 'x')
				cnt += ft_handle_hex(&args);
			else if (fmt[i] == 'X')
				cnt += ft_handle_hex(&args);
			else
			{
				cnt = cnt + 1 + print_pct();
				write (1, &fmt[i], 1);
			}
			i++;
		}
		else // This is for handling the case where % is the last thing
			cnt += print_pct();
	}
	va_end(args); 
	return (cnt);
}
#include <stdio.h>
int main()
{
	printf("%x\n", 26); // should return 1a
}
