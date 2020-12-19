/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:18:20 by agautier          #+#    #+#             */
/*   Updated: 2020/12/19 20:18:22 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_data_parsed(int *data_parsed)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		data_parsed[index] = 0;
		index++;
	}
}

void		global_parse(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		data_parsed[8];
	char	*buffer;

	init_data_parsed(data_parsed);
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		if (parsed_data(data_parsed))
			buffer = fill_buffer(line);
		else
			parse_data(line, game, data_parsed);
		free(line);
	}
	if (parsed_data(data_parsed))
		buffer = fill_buffer(line);
	parse_map(game, buffer);
	// printf("buffer =\n%s\n", buffer);	// TODO: Remove
	free(buffer);
	free(line);
	close(fd);
}

void		parse_data(char *line, t_game *game, int *data_parsed)
{
	const char	*tab[9] = {"R", "NO", "SO", "WE", "EA", "S", "F", "C", 0};
	int			(*const tab_f[8])(t_game *, char **, int) = {
		fill_resolution, fill_texture, fill_texture, fill_texture,
		fill_texture, fill_texture, fill_color, fill_color};
	char		**words;
	int			index;

	if (ft_strlen(line) > 0)
	{
		words = ft_split_charset(line, ft_get_whitespaces());
		index = find_elem(words, tab);
		if (index >= 0 && !(data_parsed[index] = tab_f[index](game,
			words, index)))
		{
			free_split(words);
			free(line);
			exit(1);
		}
		free_split(words);
	}
}

void		parse_map(t_game *game, char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index])
		index++;
	index--;
	while (buffer[index] == '\n' || buffer[index] == ' ')
	{
		buffer[index] = '\0';
		index--;
	}
	game->map = ft_split(buffer, '\n');
	if (!check_player(game))
		ft_error(game);
	if (!find_zeros(game))
		ft_error(game);
	if (!check_closed_map(game))
		ft_error(game);
}
