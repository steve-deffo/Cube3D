/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:47:16 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:47:19 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	amount;

	amount = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		amount++;
	}
	return (amount);
}
