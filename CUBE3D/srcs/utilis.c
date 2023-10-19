/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desteve <desteve@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:56:28 by desteve           #+#    #+#             */
/*   Updated: 2023/07/15 06:19:36 by desteve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/*create_rgb permet de créer une valeur entière représentant une 
couleur RGB en combinant les composantes 
rouge (r), verte (g) et bleue (b) dans un format spécifique.*/

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/*print_double_array est utilisée pour afficher le contenu 
d'un tableau à deux dimensions (char **map), également appelé 
double tableau. Chaque élément du tableau représente une ligne de texte.*/

void	print_double_array(t_map *m)
{
	char	**map;

	map = m->map;
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
}

/*ft_spaces_str est utilisée pour créer une chaîne de caractères
 contenant des espaces. Elle est utilisée dans le contexte de 
 la fonction make_double_array_map pour compléter les lignes 
 du tableau à deux dimensions avec des 
 espaces afin d'obtenir une largeur uniforme.*/

char	*ft_spaces_str(int width, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (width - len + 1));
	while (i < width - len)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

// The function skip_empty_lines is 
//used to skip over empty lines in the map file
/*skip_empty_lines est utilisée pour sauter les lignes 
vides lors de la lecture du fichier de configuration. 
Elle est utilisée dans le contexte de la fonction parse_file 
pour ignorer les lignes vides et passer aux lignes 
suivantes contenant des données.*/

void	skip_empty_lines(t_check *ch)
{
	ch->trimmed = ft_strtrim(ch->line, " \t\v\f\r");
	if (ch->trimmed && *(ch->trimmed))
	{
		free(ch->trimmed);
		return ;
	}
	if (ch->line)
		free(ch->line);
	if (ch->trimmed)
		free(ch->trimmed);
	while (get_next_line(ch->fd, &ch->line))
	{
		ch->trimmed = ft_strtrim(ch->line, " \t\v\f\r");
		if (ch->trimmed && *(ch->trimmed))
		{
			free(ch->trimmed);
			break ;
		}
		free(ch->line);
		ch->line = NULL;
		free(ch->trimmed);
		ch->trimmed = NULL;
	}
	if (!ch->line || !*(ch->line))
		error_exit("Error with map data!", 6);
}
