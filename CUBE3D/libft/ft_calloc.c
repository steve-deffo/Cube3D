/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:42:28 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:42:30 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	void	*temp;

	pointer = malloc((count) * size);
	if (pointer == NULL)
		return (NULL);
	temp = pointer;
	ft_memset(pointer, 0, (size * count));
	return (temp);
}
