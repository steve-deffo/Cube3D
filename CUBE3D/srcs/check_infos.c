/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:52:34 by desteve           #+#    #+#             */
/*   Updated: 2023/08/01 21:11:18 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
// check_space:Cela garantit que les espaces vides dans la carte sont 
//correctement entourés de murs ou du symbole du joueur, ce qui est
// essentiel pour assurer la validité de la carte dans le contexte du jeu.
/*check_line_for_space: Si aucun caractère autre qu'un espace 
n'est trouvé dans la ligne, cela signifie que la ligne est 
entièrement composée d'espacesvides. Dans ce cas, la variable 
space_line dans le vérificateur est définie à 1 
pour indiquer la présence d'une ligne vide. Cela peut être utilisé
 plus tard pour détecter les erreurs liées 
 aux lignes vides dans la carte.*/

/*check_map_correctness:La fonction parcourt ainsi
toute la carte et effectue les vérifications nécessaires 
pour s'assurer de sa validité. Si une erreur est détectée 
à n'importe quel moment, la fonction error_exit est appelée
pour afficher un message d'erreur et quitter le programme.*/

void	check_spaces(t_all *all, char **map, int i, int j)
{
	if (check_if_symbol_is_zero_or_player(all, map, i, j - 1)
		|| check_if_symbol_is_zero_or_player(all, map, i, j + 1)
		|| check_if_symbol_is_zero_or_player(all, map, i + 1, j)
		|| check_if_symbol_is_zero_or_player(all, map, i - 1, j)
		|| check_if_symbol_is_zero_or_player(all, map, i + 1, j + 1)
		|| check_if_symbol_is_zero_or_player(all, map, i - 1, j + 1)
		|| check_if_symbol_is_zero_or_player(all, map, i + 1, j - 1)
		|| check_if_symbol_is_zero_or_player(all, map, i - 1, j - 1))
		error_exit("Zero symbol found in wrong place", 3);
}

void	check_line_for_spaces(t_all *all, char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != ' ')
		{
			if (all->checker->space_line == 1)
				error_exit("Space line inside the map", 4);
			return ;
		}
		j++;
	}
	all->checker->space_line = 1;
}

void	check_map_correctness(t_all *all)
{
	char		**map;
	int			i;
	int			j;

	i = -1;
	map = all->m->map;
	while (map[i] && (++i < all->m->height))
	{
		j = -1;
		check_line_for_spaces(all, map, i);
		while (map[i][++j] && j < all->m->width)
		{
			if (map[i][j] == ' ')
				check_spaces(all, map, i, j);
			else if (map[i][j] == '0')
				check_zeros_at_corners(all, i, j);
			else if (map[i][j] == '1')
				;
			else if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				check_one_player(all, map, i, j);
			else
				error_exit("Invalid symbol in map", 5);
		}
	}
}
