/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:52:21 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:52:24 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_prow(char s, const char *symbols)
{
	while (*symbols)
	{
		if (*symbols == s)
			return (1);
		symbols++;
	}
	return (0);
}

static char	*ft_trimstring(const char *s1, size_t cop, int a)
{
	char	*trimmed;
	char	*pointer;

	if (cop == 0)
	{
		pointer = malloc(sizeof(char));
		*pointer = '\0';
		return (pointer);
	}
	trimmed = malloc(sizeof(char) * (cop - a + 1));
	if (trimmed == NULL)
		return (NULL);
	pointer = trimmed;
	while (*s1 && ((cop - a) > 0))
	{
		*pointer = *s1;
		pointer++;
		s1++;
		cop--;
	}
	*pointer = '\0';
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*pointer;
	size_t	length;
	size_t	cop;
	int		a;

	a = 0;
	length = ft_strlen(s1);
	cop = length;
	pointer = (char *)s1;
	while (ft_prow(*s1, set) == 1 && *s1)
	{
		s1++;
		a++;
	}
	while (ft_prow(*(pointer + cop - 1), set) == 1)
		cop--;
	pointer = ft_trimstring(s1, cop, a);
	return (pointer);
}
