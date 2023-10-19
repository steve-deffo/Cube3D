/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:47:46 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:47:49 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*string;
	void		*new;
	char		d;

	d = c;
	string = (char *)s;
	while (n)
	{
		if (*string == d)
		{
			new = (void *)string;
			return (new);
		}
		string++;
		n--;
	}
	return (NULL);
}
