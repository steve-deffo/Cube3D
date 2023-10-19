/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_0_et_jouer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:53:08 by desteve           #+#    #+#             */
/*   Updated: 2023/08/02 16:31:31 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*check_if_map_has_player: a pour rôle de vérifier si la 
carte du jeu contient au moins un joueur 
(représenté par les symboles 'N', 'S', 'W' ou 'E'). Si aucun joueur
n'est présent sur la carte, la fonction génère une erreur et 
arrête l'exécution du programme.*/

#include "../cub3D.h"

void	check_if_map_has_player(t_all *all)
{
	if (all->checker->e == 0 && all->checker->w == 0
		&& all->checker->s == 0 && all->checker->n == 0)
		error_exit("Where is no player on the map", 12);
}

/*check_zeros_at_corners: a pour rôle de vérifier 
si le symbole '0' (zéro) est présent dans un coin 
de la carte. Elle prend en paramètres la structure t_all 
contenant les données du jeu, ainsi que les coordonnées 
i et j du symbole '0' dans la carte.*/

void	check_zeros_at_corners(t_all *all, int i, int j)
{
	if (i == 0 || i == all->m->height - 1 || j == 0 || j == all->m->width)
		error_exit("Zero is found in a corner. Wrong map", 13);
}

/*La fonction check_if_symbol_is_zero_or_player a pour 
rôle de vérifier si le symbole à une position donnée dans 
la carte est soit le symbole '0' (zéro) ou un symbole représentant 
un joueur (N, E, W, S). Elle prend en paramètres la 
structure t_all contenant les données du jeu, le tableau 
map représentant la carte, ainsi que les 
coordonnées i et j du symbole à vérifier.*/

int	check_if_symbol_is_zero_or_player(t_all *all, char **map, int i, int j)
{
	return ((i >= 0 && i < all->m->height) && (j >= 0 && j < all->m->width)
		&& (map[i][j] == '0' || map[i][j] == 'N'
		|| map[i][j] == 'E' || map[i][j] == 'W'
		|| map[i][j] == 'S'));
}

/*La fonction effectue une série de vérifications 
conditionnelles pour déterminer si les coordonnées 
i et j sont à l'intérieur des limites de la carte 
(i doit être compris entre 0 et la hauteur de la 
carte - 1, et j doit être compris entre 0 et la largeur de la carte - 1).
 Elle vérifie ensuite si le symbole à ces coordonnées est égal à '0'.*/

int	check_if_symbol_is_zero(t_all *all, char **map, int i, int j)
{
	return ((i >= 0 && i < all->m->height)
		&& (j >= 0 && j < all->m->width) && map[i][j] == '0');
}

/*En résumé, cette fonction effectue des vérifications 
pour s'assurer que le joueur est correctement positionné, 
qu'il y a un seul joueur dans la carte, et que le joueur n'est
pas entouré de murs. Elle joue un rôle important dans 
la validation et l'initialisation des données du joueur dans le jeu.*/

void	check_one_player(t_all *all, char **map, int i, int j)
{
	if (i == 0 || i == all->m->height)
		error_exit("Player in the wrong place", 14);
	if (map[i][j] == 'N' && all->checker->n == 0)
		all->checker->n++;
	else if (map[i][j] == 'E' && all->checker->e == 0)
		all->checker->e++;
	else if (map[i][j] == 'W' && all->checker->w == 0)
		all->checker->w++;
	else if (map[i][j] == 'S' && all->checker->s == 0)
		all->checker->s++;
	else
		error_exit("Something wrong with player", 15);
	if (all->checker->n + all->checker->e + all->checker->s
		+ all->checker->w > 1)
		error_exit("Something wrong with player", 15);
	add_player_to_struct(all, i, j, map[i][j]);
}
