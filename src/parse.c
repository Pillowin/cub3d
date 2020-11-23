/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:34:50 by agautier          #+#    #+#             */
/*   Updated: 2020/11/23 21:56:17 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		global_parse(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		parse_line(line, game);
		ft_free(line);
	}
	// parse_line(line, game);
	ft_free(line);
	close(fd);
}

static int	find_elem(char **words, const char **tab)
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

void		parse_line(char *line, t_game *game)
{
	const char	*tab[9] = {"R", "NO", "SO", "WE", "EA", "S", "F", "C", 0};
	int			(*const tab_f[8])(t_game *, char **, int) = {
		fill_resolution, fill_texture, fill_texture, fill_texture, fill_texture,
		fill_texture, fill_color, fill_color};
	char		**words;
	int			index;

	words = ft_split_charset(line, ft_get_whitespaces());
	index = find_elem(words, tab);
	if (index >= 0)
		if (!tab_f[index](game, words, index))
		{
			free_split(words);
			ft_free(line);
			exit(1);
		}
	free_split(words);
}
