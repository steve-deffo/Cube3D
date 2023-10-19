/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:03:46 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 16:03:49 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_num(const char *s)
{
	long long int	number;

	number = 0;
	while (*s >= '0' && *s <= '9')
	{
		number = number * 10 + *s - '0';
		s++;
	}
	return (number);
}

long int	ft_atoi(const char *str)
{
	long int		number;
	int				min;

	min = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (!((*str >= '0' && *str <= '9') || *str == '+' || *str == '-'))
		return (0);
	if ((*str == '+' || *str == '-') && \
		!(*(str + 1) >= '0' && (*(str + 1) <= '9')))
		return (0);
	if (*str == '-')
	{
		min = 1;
		str++;
	}
	if (*str == '+')
		str++;
	number = ft_num(str);
	if (min == 1)
		number = -number;
	return (number);
}
