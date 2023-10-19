/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:56:17 by desteve           #+#    #+#             */
/*   Updated: 2023/08/01 19:06:09 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*a fonction raycaster_start exécute l'algorithme de raycasting pour 
chaque colonne de pixels de l'écran en effectuant des calculs pour 
déterminer les directions des rayons, les coordonnées de la carte, 
les distances delta et en appelant les fonctions nécessaires pour 
effectuer l'algorithme DDA et afficher les pixels correspondants sur l'écran.*/

void	raycaster_start(t_all *all)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		all->rc->camera_x = 2 * x / (double)WIDTH - 1;
		all->rc->ray_dir_x = all->player->dir_x
			+ all->plane->plane_x * all->rc->camera_x;
		all->rc->ray_dir_y = all->player->dir_y
			+ all->plane->plane_y * all->rc->camera_x;
		all->rc->map_x = (int)(all->player->pos_x);
		all->rc->map_y = (int)(all->player->pos_y);
		if (all->rc->ray_dir_x == 0)
			all->rc->delt_dist_x = 1e30;
		else
			all->rc->delt_dist_x = fabs(1 / all->rc->ray_dir_x);
		if (all->rc->ray_dir_y == 0)
			all->rc->delt_dist_y = 1e30;
		else
			all->rc->delt_dist_y = fabs(1 / all->rc->ray_dir_y);
		raycaster_second_part(all);
		dda_algorithm(all);
		print_raycasted_map(x, all);
	}
}

/*raycaster_second_part calcule les valeurs des variables 
nécessaires pour déterminer les distances de projection des 
rayons jusqu'à la prochaine intersection avec une ligne de 
la carte, en fonction de la direction des rayons sur les 
axes x et y. Ces valeurs seront utilisées dans l'algorithme
DDA pour parcourir les intersections de rayon avec les lignes de la carte.*/

void	raycaster_second_part(t_all *all)
{
	t_raycast	*rc;

	rc = all->rc;
	rc->hit = 0;
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->s_dist_x = (all->player->pos_x - rc->map_x) * rc->delt_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->s_dist_x = (rc->map_x + 1.0 - all->player->pos_x) * rc->delt_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->s_dist_y = (all->player->pos_y - rc->map_y) * rc->delt_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->s_dist_y = (rc->map_y + 1.0 - all->player->pos_y) * rc->delt_dist_y;
	}
	all->rc = rc;
}

/*dda_algorithm utilise l'algorithme DDA pour parcourir les 
intersections de rayons avec les lignes de la carte, mettre 
à jour les variables en fonction des positions de la carte, 
des directions du rayon et des distances de projection, 
et trouver le point d'impact du rayon sur un mur.*/

void	dda_algorithm(t_all *all)
{
	while (all->rc->hit == 0)
	{
		if (all->rc->s_dist_x < all->rc->s_dist_y)
		{
			all->rc->s_dist_x += all->rc->delt_dist_x;
			all->rc->map_x += all->rc->step_x;
			all->rc->side = 0;
		}
		else
		{
			all->rc->s_dist_y += all->rc->delt_dist_y;
			all->rc->map_y += all->rc->step_y;
			all->rc->side = 1;
		}
		if (all->m->map[all->rc->map_y][all->rc->map_x] == '1')
			all->rc->hit = 1;
		dda_algorithm_second_part(all);
	}
}

/*dda_algorithm_second_part calcule la distance perpendiculaire 
entre le point d'impact du rayon et la position actuelle du mur, 
détermine la hauteur de ligne du mur à dessiner à l'écran et 
calcule les coordonnées de début et de fin de la ligne à dessiner. 
Ces valeurs sont utilisées ultérieurement pour le rendu graphique.*/

void	dda_algorithm_second_part(t_all *all)
{
	if (all->rc->side == 0)
		all->rc->perp_wall_dist = all->rc->s_dist_x - all->rc->delt_dist_x;
	else
		all->rc->perp_wall_dist = all->rc->s_dist_y - all->rc->delt_dist_y;
	all->rc->line_height = (int)(HEIGHT / all->rc->perp_wall_dist);
	all->rc->draw_start = -all->rc->line_height / 2 + HEIGHT / 2;
	if (all->rc->draw_start < 0)
		all->rc->draw_start = 0;
	all->rc->draw_end = all->rc->line_height / 2 + HEIGHT / 2;
	if (all->rc->draw_end >= HEIGHT)
		all->rc->draw_end = HEIGHT - 1;
}
