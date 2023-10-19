/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_ciel_et_sol_checker.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:53:29 by desteve           #+#    #+#             */
/*   Updated: 2023/08/01 23:23:41 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*La fonction ft_atoi_color est utilisée 
pour convertir une chaîne de 
caractères représentant une valeur de 
couleur en un entier. Elle prend 
en paramètre la chaîne de caractères
 str à convertir
if error - ft_atoi_color returns -1
else it return num from 0 to 255*/

int	ft_atoi_color(const char *str)
{
	int	num;

	num = 0;
	if (!*str || (*str < '1' && *str > '9'))
		return (-1);
	if (*str == '0')
	{
		if (str[1] && str[1] >= '0' && str[1] <= '9')
			return (-1);
		return (0);
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
		if (num > 255)
			return (-1);
	}
	return (num);
}

/*add_color_to_struct permet d'extraire 
les composantes de couleur d'une
 chaîne de caractères et de les 
 stocker dans une structure
  t_color pour une utilisation ultérieure.*/

char	*add_color_to_struct(char *str, t_color *col, int index)
{
	int	num;

	if (!str)
		error_exit("Wrong color data", 17);
	num = ft_atoi_color(str);
	if (num == -1)
		error_exit("RGB data of color is wrong", 18);
	else
	{
		if (index == 0)
			col->r = num;
		else if (index == 1)
			col->g = num;
		else
			col->b = num;
		while (*str && *str >= '0' && *str <= '9')
			str++;
	}
	return (str);
}

/*check_correctness_of_color s'assure que les données de couleur 
sont correctement formatées en vérifiant la présence de virgules 
entre les composantes de couleur et en 
signalant une erreur si le format est incorrect.*/
void	check_correctness_of_color(char *str, t_color *col)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		str = add_color_to_struct(str, col, i);
		if ((i < 2 && *str) && (*str == ',' || *str == ' '))
			str++;
		else if (((i < 2) && (*str != ',' || *str != ' ')) || (i == 2 && *str))
			error_exit("Wrong format of color data", 19);
		++i;
	}
}

/*add_color_of_floor_and_ceiling permet de stocker les couleurs du sol et du
 plafond dans la structure de données t_data en vérifiant leur validité et
  en s'assurant qu'elles ne sont pas répétées.*/

void	add_color_of_floor_and_ceiling(char **args, t_check *ch, t_data *data)
{
	t_color	col;

	check_correctness_of_color(args[1], &col);
	if (!ft_strncmp("F", args[0], 2) && !ch->floor)
	{
		data->floor[0] = col.r;
		data->floor[1] = col.g;
		data->floor[2] = col.b;
		ch->floor++;
	}
	else if (!ft_strncmp("C", args[0], 2) && !ch->ceiling)
	{
		data->ceiling[0] = col.r;
		data->ceiling[1] = col.g;
		data->ceiling[2] = col.b;
		ch->ceiling++;
	}
	else
		error_exit("Identifiers repetitive", 20);
}
