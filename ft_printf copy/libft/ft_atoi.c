/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:57:56 by mel-assa          #+#    #+#             */
/*   Updated: 2025/09/28 12:46:53 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			sgn;
	long long	nmr;

	nmr = 0;
	sgn = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sgn = -sgn;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (nmr >= LLONG_MAX / 10 && (str[i] - '0') > (LLONG_MAX % 10))
		{
			if (sgn > 0)
				return (-1);
			else
				return (0);
		}
		nmr = (nmr * 10) + (str[i++] - '0');
	}
	return (nmr * sgn);
}
