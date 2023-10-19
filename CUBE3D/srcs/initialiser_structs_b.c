/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialiser_structs_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:54:33 by desteve           #+#    #+#             */
/*   Updated: 2023/08/01 22:48:35 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*Cette fonction est utilisée pour remplir les vecteurs de direction 
et de plan de projection en fonction de la direction du joueur, 
ce qui est nécessaire pour effectuer le raycasting et le rendu du jeu.*/

void	fill_direction_vector_2(char direction, t_all *all)
{
	if (direction == 'S')
	{
		all->player->dir_x = 0;
		all->player->dir_y = 1;
		all->plane->plane_x = 0.66;
		all->plane->plane_y = 0;
	}
	else if (direction == 'N')
	{
		all->player->dir_x = 0;
		all->player->dir_y = -1;
		all->plane->plane_x = -0.66;
		all->plane->plane_y = 0;
	}
}

void	fill_direction_vector(char direction, t_all *all)
{
	if (direction == 'W')
	{
		all->player->dir_x = -1;
		all->player->dir_y = 0;
		all->plane->plane_x = 0;
		all->plane->plane_y = 0.66;
	}
	else if (direction == 'E')
	{
		all->player->dir_x = 1;
		all->player->dir_y = 0;
		all->plane->plane_x = 0;
		all->plane->plane_y = -0.66;
	}
	else if (direction == 'S' || direction == 'N')
		fill_direction_vector_2(direction, all);
}

/*Cette fonction est utilisée pour ajouter les informations du 
joueur à la structure principale t_all, ce qui permet de stocker 
et d'accéder aux informations du joueur lors de l'exécution du jeu.*/

void	add_player_to_struct(t_all *all, int i, int j, char direction)
{
	t_player	*player;
	t_plane		*plane;

	player = malloc(sizeof(t_player));
	plane = malloc(sizeof(t_plane));
	all->plane = plane;
	player->pos_x = j + 0.5;
	player->pos_y = i + 0.5;
	all->m->map[i][j] = '0';
	all->player = player;
	fill_direction_vector(direction, all);
}
