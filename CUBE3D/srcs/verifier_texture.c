/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifier_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:52:54 by desteve           #+#    #+#             */
/*   Updated: 2023/08/01 23:26:37 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

//  the check_path_to_texture function is used to
//validate the path to a texture file by checking its extension.

void	check_path_to_texture(char *str)
{
	int	len;
	int	fd;

	len = ft_strlen(str);
	if (ft_strncmp(".xpm", str + len - 4, 5))
		error_exit("Wrong texture format", 7);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_exit("Couldn't open file with texture", 8);
	close(fd);
}

// the add_path_to_texture function is used to 
//store the path to the corresponding texture in the 
//t_data structure based on the texture identifier

void	add_path_to_texture(char **args, t_check *ch, t_data *data)
{
	check_path_to_texture(args[1]);
	if (!ft_strncmp("NO", args[0], 3) && !ch->nt)
	{
		data->n_texture = ft_strdup(args[1]);
		ch->nt++;
	}
	else if (!ft_strncmp("SO", args[0], 3) && !ch->st)
	{
		data->s_texture = ft_strdup(args[1]);
		ch->st++;
	}
	else if (!ft_strncmp("WE", args[0], 3) && !ch->wt)
	{
		data->w_texture = ft_strdup(args[1]);
		ch->wt++;
	}
	else if (!ft_strncmp("EA", args[0], 3) && !ch->et)
	{
		data->e_texture = ft_strdup(args[1]);
		ch->et++;
	}
	else
		error_exit("Identifiers repetitive", 9);
}

// The add_texture_to_struct function is 
//responsible for parsing and adding texture information to the data structure

// the if condition it is use to pars the texture argument
// args[2] is use to check if we have 3 argument in the array
// !args[0] !args[1] checks if the first argument
// and second(argument is missing or empty

// the if condition is use to check if the 1 
//argument in the actuall line matches one of the specified texture identifiers

void	add_texture_to_struct(t_data *data, t_check *ch)
{
	char	**args;

	args = ft_split(ch->trimmed, ' ');
	free(ch->trimmed);
	ch->trimmed = NULL;
	if (args[2] || !args[0] || !args[1])
		error_exit("Wrong amount of args in texture parsing", 10);
	if (!ft_strncmp("NO", args[0], 3) || !ft_strncmp("SO", args[0], 3)
		|| !ft_strncmp("WE", args[0], 3) || !ft_strncmp("EA", args[0], 3))
		add_path_to_texture(args, ch, data);
	else if (!ft_strncmp("F", args[0], 2) || !ft_strncmp("C", args[0], 2))
		add_color_of_floor_and_ceiling(args, ch, data);
	else
		error_exit("Wrong texture identifier", 11);
	ch->amount++;
	free_double_array(args);
}
