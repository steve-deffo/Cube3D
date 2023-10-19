/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:55:58 by desteve           #+#    #+#             */
/*   Updated: 2023/08/01 20:47:16 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*La fonction make_double_array_map_2 est une fonction interne qui
 fait partie du processus de conversion de la liste chaînée en
  tableau à deux dimensions pour représenter la carte du jeu.*/

static void	make_double_array_map_2(t_map *m, t_all *all, t_list *head)
{
	m->map[++all->i] = NULL;
	m->height = all->height;
	m->width = all->width;
	all->m = m;
	free_chained_list(head);
}

/*La fonction make_double_array_map permet donc de convertir
 une liste chaînée en un tableau à deux dimensions représentant 
 la carte du jeu, en prenant en compte la hauteur et la largeur spécifiées.*/

void	make_double_array_map(t_all *all, t_list *lst, int height, int width)
{
	t_list	*head;
	t_map	*m;
	char	*temp;

	all->i = -1;
	m = malloc(sizeof(t_map));
	m->map = malloc(sizeof(char *) * (height + 1));
	head = lst;
	while (lst)
	{
		if ((int)ft_strlen(lst->content) < width)
		{
			temp = ft_spaces_str(width, ft_strlen(lst->content));
			m->map[++all->i] = ft_strjoin(lst->content, temp);
			free(temp);
		}
		else
			m->map[++all->i] = ft_strdup(lst->content);
		free(lst->content);
		lst = lst->next;
	}
	make_double_array_map_2(m, all, head);
}

/*continue_parsing est responsable de la poursuite du processus 
d'analyse et de validation des données extraites du fichier de 
configuration. Elle convertit la liste chaînée en une carte du 
jeu représentée par un tableau à deux dimensions, effectue 
des vérifications de validité sur la carte 
et garantit la présence d'un joueur.*/

void	continue_parsing(t_all *all, t_list *lst)
{
	make_double_array_map(all, lst, all->height, all->width);
	init_player_checker_struct(all);
	check_map_correctness(all);
	check_if_map_has_player(all);
}

/*, la fonction parse_map est responsable de l'analyse de la 
section de la carte du fichier de configuration. Elle extrait 
les lignes de la carte, détermine la largeur et la hauteur de 
la carte, et appelle ensuite la fonction continue_parsing pour 
poursuivre le processus d'analyse et de validation des données.*/

void	parse_map(t_check *ch, t_all *all)
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ch->line));
	all->width = ft_strlen(ch->line);
	all->height = 1;
	while (get_next_line(ch->fd, &ch->line))
	{
		ft_lstadd_back(&lst, ft_lstnew(ch->line));
		all->temp = ft_strlen(ch->line);
		if (all->temp > all->width)
			all->width = all->temp;
		all->height++;
	}
	if (all->height != 1)
	{
		ch->trimmed = ft_strtrim(ch->line, " \t\n");
		if (*(ch->trimmed))
		{
			ft_lstadd_back(&lst, ft_lstnew(ch->line));
			all->height++;
		}
		free(ch->trimmed);
	}
	continue_parsing(all, lst);
}

/*
the parse_data function is used to parse the elements in the map file.

we call the init_check_struct function to initializes 
the members of a t_check structure

we allocates memory for a t_data structure using the malloc function.

we use open on the map to use the mode O_RDONLY it will
 return a value depending on if it succed or not
this value in a numeric identifier that represent the open
 file its named a file descriptor
we check next  if an error occuared during the process

in the while loop we will check line by line the map file until getnextline 
can no more read or the the number of argument is low than 6
the get_next_line function is used to read a file line by line. 
It reads each line from the file and stores it in the line variable

we trimm the actual line using ft_strtrim function from the spacing charcater.
we store the trimmed line in the trimmed variable.

the if condition check if trimmed is not empty or a null pointer
if its valide the add_texture_to_struct function is call

if not we free and go to the next line

we us the The function skip_empty_lines 
to skip over empty lines in the map file */

void	parse_data(char **argv, t_all *all)
{
	t_data	*data;
	t_check	ch;

	init_check_struct(&ch);
	data = malloc(sizeof(t_data));
	if (!data)
		error_exit("Malloc error", 21);
	ch.fd = open(argv[1], O_RDONLY);
	if (ch.fd == -1)
		error_exit("Couldn't open the file", 22);
	while (get_next_line(ch.fd, &ch.line) && ch.amount < 6)
	{
		ch.trimmed = ft_strtrim(ch.line, " \t\v\f\r");
		free(ch.line);
		if (ch.trimmed && *(ch.trimmed))
			add_texture_to_struct(data, &ch);
		else if (ch.trimmed)
			free(ch.trimmed);
	}
	if (ch.amount < 6)
		error_exit("Not enough data", 23);
	skip_empty_lines(&ch);
	parse_map(&ch, all);
	all->data = data;
	close(ch.fd);
}
