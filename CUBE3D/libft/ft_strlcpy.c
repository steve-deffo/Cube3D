/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:51:08 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:51:10 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	actsize;
	size_t	length;

	length = ft_strlen(src);
	if (dstsize == 0)
		return (length);
	actsize = dstsize - 1;
	while (actsize && *src)
	{
		*dst = *src;
		dst++;
		src++;
		actsize--;
	}
	*dst = '\0';
	return (length);
}
