/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-assa <mel-assa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 21:04:38 by mel-assa          #+#    #+#             */
/*   Updated: 2025/09/04 21:24:28 by mel-assa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_length(const char *s, char c)
{
	size_t	wordlen;

	wordlen = 0;
	while (s[wordlen] && s[wordlen] != c)
	{
		wordlen++;
	}
	return (wordlen);
}

static char	**fill_word(size_t i, const char *s, char c, char **splt)
{
	size_t	wordlen;
	size_t	j;
	size_t	l;

	wordlen = word_length(s, c);
	splt[i] = malloc(wordlen + 1);
	if (!splt[i])
	{
		l = 0;
		while (l < i)
			free(splt[l++]);
		free(splt);
		return (NULL);
	}
	j = 0;
	while (j < wordlen)
	{
		splt[i][j] = s[j];
		j++;
	}
	splt[i][j] = '\0';
	return (splt);
}

static char	**fill_strarray(char **splt, const char *s, size_t words, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (i < words)
	{
		while (s[k])
		{
			if (s[k] == c)
				k++;
			else
			{
				splt = fill_word(i, &s[k], c, splt);
				if (!splt)
					return (NULL);
				k += word_length(&s[k], c);
				break ;
			}
		}
		i++;
	}
	splt[words] = NULL;
	return (splt);
}

static size_t	words_counter(char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**splt;

	if (!s)
		return (NULL);
	words = words_counter(s, c);
	splt = malloc(sizeof(char *) * (words + 1));
	if (!splt)
		return (NULL);
	splt = fill_strarray(splt, s, words, c);
	return (splt);
}
