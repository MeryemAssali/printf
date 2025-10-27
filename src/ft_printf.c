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

#include "ft_printf.h"
//include "../libft/libft.h"

int ft_strlen(char *stn)
{
	int i = 0;
	while (stn[i])
	{
		i++;
	}
	return(i);
}

int ft_printf(const char *fmt, ...)
{
	va_list args; // Declares the variable to access the variable (unkown) arguments
	va_start (args, fmt); // Start scanning right after the fixed arguement (fmt string in this case)
	char c;
	char *str;
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	while (fmt[i])			//printf("%d\n",ft_printf("I lov%%c 42. Hell%c\n", 'e','o'));
	{
		if (fmt[i] != '%') // if it's not %
		{
			cnt++; // count it 
			write(1, &fmt[i++], 1); // Print it. Go to the next one.
		}
		else // if it is %
		{
			// Handling double percentge sign
			if (fmt[i+1] == '%' && fmt[i+1]) // Peek into the next one. If it's also %, and we're still not at the end of the string
			{
				write(1, "%", 1); // print %
				i+=2; // skip both %
				cnt++;
			}
			// Handeling variable number of Characters
			else if (fmt[i+1] == 'c' && fmt[i+1]) // when you encounter a %c
			{
				c = va_arg(args, int); // get the NEXT arguement that's an integer and cast it to a character c (and so on)
				write(1,&c,1); // print that character
				i+=2; // trasverse throught the format string
				cnt++;
			}

			// Handeling a string
			else if (fmt[i+1] == 's' && fmt[i+1])
			{
				str = va_arg(args, char *);
				write(1, &str[0], ft_strlen(str));
				i+=2;
				cnt+= ft_strlen(str);
			}

		}
	}
	va_end(args); // End trasversal
	return (cnt);
}

#include <stdio.h>
int main()
{
	printf("%d\n",ft_printf("%c lov%c 42 %s\n", 'I','e',"Abu Dhabi"));
}