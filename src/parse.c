/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:34:50 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 22:34:18 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_parse(char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		parse_line(line, map);
		// printf("|%s|\n\n", line);
		ft_free(line);
	}
	parse_line(line, map);
	ft_free(line);
	// printf("|%s|\n\n", line);
	// printf("map->ceiling.r = %d\n", map->ceiling.r);
	// printf("map->ceiling.g = %d\n", map->ceiling.g);
	// printf("map->ceiling.b = %d\n", map->ceiling.b);
	// printf("map->floor.r = %d\n", map->floor.r);
	// printf("map->floor.g = %d\n", map->floor.g);
	// printf("map->floor.b = %d\n\n", map->floor.b);
	// printf("map->north = %s\n", map->north);
	// printf("map->south = %s\n", map->south);
	// printf("map->west = %s\n", map->west);
	// printf("map->east = %s\n", map->east);
	// printf("map->sprite = %s\n", map->sprite);
	close(fd);
}

int		find_elem(char **words, const char **tab)
{
	int	i;

	i = 0;
	while (tab[i] && words[0])
	{
		if (!ft_strncmp(tab[i], words[0], ft_strlen(words[0]) + 1))
			return (i);
		i++;
	}
	return (-1);
}

void	parse_line(char *line, t_map *map)
{
	const char	*tab[9] = {"R", "NO", "SO", "WE", "EA", "S", "F", "C", 0};
	int			(*const tab_f[8])(t_map *, char **, int) = {
		fill_resolution, fill_texture, fill_texture, fill_texture, fill_texture,
		fill_texture, fill_color, fill_color};
	char		**words;
	int			index;

	words = ft_split_charset(line, ft_get_whitespaces());
	index = find_elem(words, tab);
	if (index >= 0)
		if (!tab_f[index](map, words, index))
		{
			ft_free(line);
			free_split(words);
			exit(1);
		}
	free_split(words);
}
