/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:53:38 by desteve           #+#    #+#             */
/*   Updated: 2023/06/25 17:53:42 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ret(int ret)
{
	if (ret > 0)
		return (1);
	else
		return (ret);
}

static void	remain_to_line(char **remain, char **line)
{
	char	*temp;
	char	*find_n;

	if (!*remain)
	{
		*line = ft_strdup("");
		return ;
	}
	find_n = ft_strchr_g(*remain, '\n');
	if (!find_n)
	{
		*line = ft_strdup(*remain);
		free(*remain);
		*remain = NULL;
		return ;
	}
	else
	{
		temp = *remain;
		*find_n = '\0';
		*line = ft_strdup(*remain);
		find_n++;
		*remain = ft_strdup(find_n);
		free(temp);
	}
}

static int	remain_check(char *remain)
{
	if (!remain)
		return (0);
	if (ft_strchr_g(remain, '\n'))
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*remain;
	char		*temp;
	int			ret;

	ret = 1;
	if (fd < 0 || !(line) || BUFFER_SIZE <= 0)
		return (-1);
	while (ret && !remain_check(remain))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			*line = NULL;
			return (-1);
		}
		buf[ret] = '\0';
		temp = remain;
		remain = ft_strjoin(temp, buf);
		if (temp)
			free(temp);
	}
	remain_to_line(&remain, line);
	return (ft_ret(ret));
}
