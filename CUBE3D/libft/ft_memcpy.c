/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:48:05 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:48:08 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*temp;
	char	*source;

	temp = (char *) dst;
	source = (char *) src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n)
	{
		*temp = *source;
		source++;
		temp++;
		n--;
	}
	return (dst);
}
