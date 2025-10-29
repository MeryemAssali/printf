/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:21:12 by mel-assa          #+#    #+#             */
/*   Updated: 2025/10/28 22:03:20 by mel-assa         ###   ########.fr       */
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
	char nt;

	nt = va_arg(args, int);
	write(1, &nt, 1);
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
			else if (fmt[i] == 'd')
				cnt += handle_d (&args);
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
// #include <stdio.h>
// int main()
// {
// 	printf("%d\n",ft_printf("%c lov%c 42 %s\t", 'I','e',"Abu Dhabi"));
// 	printf("%d\n",ft_printf("A%mZ\t",'x'));
// 	printf("%d\n",ft_printf("[%s]\t", "hi"));
// 	printf("%d\n",ft_printf("100%% done\t")); 
// 	ft_printf("[%s]\n", NULL);
// }