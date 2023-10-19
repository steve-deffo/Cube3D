/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:50:03 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:50:06 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s == c && *s)
		s++;
	if (*s == '\0')
		return (words);
	while (*s)
	{
		while (*s != c && *s)
			s++;
		words++;
		while (*s == c && *s)
			s++;
	}
	return (words);
}

static int	ft_length(char const *s, char c)
{
	int	a;

	a = 0;
	while (*s != c && *s)
	{
		a++;
		s++;
	}
	return (a);
}

static char	**ft_free(char **split)
{
	while (split)
	{
		free (*split);
		split++;
	}
	return (NULL);
}

static char	**ft_memalloc(char const *s, char c, int words, char **split)
{
	int	i;
	int	a;

	a = 0;
	while (words)
	{
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		split[a] = malloc(sizeof(char) * ft_length(s, c) + 1);
		if (!split[a])
			return (ft_free(split));
		i = 0;
		while (*s != c && *s)
		{
			split[a][i] = *s;
			i++;
			s++;
		}
		split[a][i] = '\0';
		words--;
		a++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	if (!s)
		return (NULL);
	words = ft_words(s, c);
	if (!words)
	{
		split = malloc(sizeof(char *));
		if (!split)
			return (NULL);
		*split = 0;
		return (split);
	}
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	split = ft_memalloc(s, c, words, split);
	if (split == NULL)
		free (split);
	split[words] = NULL;
	return (split);
}
