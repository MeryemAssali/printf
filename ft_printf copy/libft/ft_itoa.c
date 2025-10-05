/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 21:05:05 by mel-assa          #+#    #+#             */
/*   Updated: 2025/09/04 21:05:09 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	to_positive(int n)
{
	long	nbr;

	if (n < 0)
		nbr = -(long)n;
	else
		nbr = n;
	return (nbr);
}

static int	digit_count(long n)
{
	int	ndigits;

	ndigits = 1;
	while (n / 10)
	{
		n /= 10;
		ndigits++;
	}
	return (ndigits);
}

static char	*allocate_memory(int n, int ndigits)
{
	char	*str;

	if (n < 0)
		str = malloc(ndigits + 2);
	else
		str = malloc(ndigits + 1);
	if (!str)
		return (NULL);
	return (str);
}

static char	*write_number_to_str(char *str, int n, int ndigits, long nbr)
{
	int	i;

	if (n < 0)
	{
		str[0] = '-';
		i = ndigits;
		str[ndigits + 1] = '\0';
	}
	else
	{
		i = ndigits - 1;
		str[ndigits] = '\0';
	}
	while (i >= 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr /= 10;
		if (n < 0 && i == 0)
			break ;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		ndigits;
	long	nbr;

	nbr = to_positive(n);
	ndigits = digit_count(nbr);
	str = allocate_memory(n, ndigits);
	if (!str)
		return (NULL);
	str = write_number_to_str(str, n, ndigits, nbr);
	return (str);
}
