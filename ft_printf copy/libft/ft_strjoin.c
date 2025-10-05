/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:29:32 by mel-assa          #+#    #+#             */
/*   Updated: 2025/09/04 22:29:35 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*stn;

	if (!s1 || !s2)
		return (NULL);
	stn = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!stn)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		stn[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		stn[i + j] = s2[j];
		j++;
	}
	stn[i + j] = '\0';
	return (stn);
}
