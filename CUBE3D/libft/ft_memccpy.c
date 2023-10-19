/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:47:34 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:47:37 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	symbol;

	symbol = c;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n)
	{
		if (*source == symbol)
		{
			*dest = *source;
			dest++;
			return (dest);
		}
		*dest = *source;
		source++;
		dest++;
		n--;
	}
	return (NULL);
}
