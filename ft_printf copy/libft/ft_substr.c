/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 18:50:31 by mel-assa          #+#    #+#             */
/*   Updated: 2025/09/07 19:01:00 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substrn;
	char	*nstr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		nstr = malloc(1);
		if (!nstr)
			return (NULL);
		nstr[0] = '\0';
		return (nstr);
	}
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	substrn = malloc(len + 1);
	if (!substrn)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		substrn[i++] = s[start++];
	substrn[i] = '\0';
	return (substrn);
}
