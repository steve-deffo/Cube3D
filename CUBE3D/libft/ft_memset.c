/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:48:37 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:48:40 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	symbol;
	char			*str;

	str = (char *)b;
	symbol = c;
	while (len)
	{
		*str = symbol;
		str++;
		len--;
	}
	return (b);
}
