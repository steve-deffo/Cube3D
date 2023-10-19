/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:52:12 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:52:15 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*new;
	int		a;

	a = ft_strlen(s);
	while (a >= 0)
	{
		if (*(s + a) == c)
		{
			new = (char *)(s + a);
			return (new);
		}
		a--;
	}
	new = 0;
	return (new);
}
