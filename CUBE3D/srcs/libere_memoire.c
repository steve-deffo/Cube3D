/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memoire.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:54:18 by desteve           #+#    #+#             */
/*   Updated: 2023/07/30 23:42:20 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*free_chained_list libère la mémoire allouée pour chaque élément
 de la liste chaînée libft en itérant à travers la liste et en utilisant 
 la fonction free pour chaque élément. Cela permet de libérer complètement 
 la mémoire utilisée par la liste chaînée.*/

void	free_chained_list(t_list *head)
{
	t_list	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/*ree_double_array libère la mémoire allouée pour un tableau à double 
dimension en itérant à travers le tableau, en libérant la mémoire de 
chaque chaîne de caractères individuelle, puis en libérant 
la mémoire du tableau lui-même.*/
void	free_double_array(char **arr)
{
	char	**pointer;

	pointer = arr;
	while (*arr)
	{
		free(*arr);
		*arr = NULL;
		arr++;
	}
	free(pointer);
	arr = NULL;
}

/*En résumé, la fonction free_memory libère la mémoire 
allouée pour toutes les structures et tableaux utilisés dans le programme, 
assurant ainsi une libération correcte de la 
mémoire et évitant les fuites de mémoire.*/
void	free_memory(t_all *all)
{
	free(all->data->e_texture);
	free(all->data->s_texture);
	free(all->data->n_texture);
	free(all->data->w_texture);
	free(all->data);
	free_double_array(all->m->map);
	free(all->m);
	free(all->rc);
	free(all->checker);
	free(all->player);
	free(all->plane);
	free(all->s_tex);
	free(all->n_tex);
	free(all->w_tex);
	free(all->e_tex);
}

int	close_win(t_all *all)
{
	free_memory(all);
	mlx_destroy_image(all->win->mlx, all->win->img);
	mlx_destroy_window(all->win->mlx, all->win->win);
	free(all->win);
	printf("Game finished!\n");
	exit(0);
}

void	check_malloc_err(char *data, char *message, int num)
{
	if (!data)
		error_exit(message, num);
}
