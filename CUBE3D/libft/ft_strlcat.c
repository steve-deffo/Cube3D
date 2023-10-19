/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:50:53 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:50:55 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlength;
	size_t	srclength;
	size_t	actsize;

	dstlength = ft_strlen(dst);
	srclength = ft_strlen(src);
	actsize = dstsize - dstlength - 1;
	if (dstsize == 0)
		return (srclength);
	if (dstlength >= dstsize)
		return (dstsize + srclength);
	dst = dst + dstlength;
	while (*src && actsize)
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
		actsize--;
	}
	*dst = '\0';
	return (dstlength + srclength);
}
