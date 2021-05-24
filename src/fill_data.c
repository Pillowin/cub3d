/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:19:11 by agautier          #+#    #+#             */
/*   Updated: 2021/02/02 00:01:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			fill_resolution(t_game *game, char **words, int index)
{
	(void)index;
	if (!words[2] || words[3])
		return (0);
	game->res.x = ft_atoi(words[1]);
	game->res.y = ft_atoi(words[2]);
	if (game->res.y <= 0 || game->res.x <= 0)
		return (0);
	return (1);
}

int			fill_texture(t_game *game, char **words, int index)
{
	int		fd;
	t_img	tex_data;

	if (!words[1])
		return (0);
	*(&game->north + (index - 1)) = ft_strdup(words[1]);
	fd = open(words[1], O_RDONLY);
	if (fd == -1 || check_tex_type(words[1]))
		return (0);
	close(fd);
	init_textures(game, &tex_data, words[1]);
	if (tex_data.res.x != 64 || tex_data.res.y != 64)
		return (0);
	*(&game->north_data + (index - 1)) = tex_data;
	return (1);
}

static char	*concatenate(char **words)
{
	int		i;
	char	*tmp;
	char	*cols;

	cols = ft_calloc(sizeof(*cols), 1);
	i = 1;
	while (words[i])
	{
		if (ft_strlen(cols) > 0 &&
			ft_isdigit(cols[ft_strlen(cols) - 1]) &&
			ft_isdigit(words[i][0]))
		{
			ft_bzero(cols, ft_strlen(cols));
			break ;
		}
		tmp = ft_strjoin(cols, words[i]);
		ft_free((void **)&cols);
		cols = tmp;
		i++;
	}
	ft_free((void **)&words[1]);
	return (cols);
}

static int	check_colors_data(char *s)
{
	int	i;
	int	nb_comma;

	i = 0;
	nb_comma = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ',')
			return (0);
		else if (s[i] == ',')
			nb_comma++;
		i++;
	}
	if (nb_comma != 2)
		return (0);
	return (1);
}

int			fill_color(t_game *game, char **words, int index)
{
	char	**colors;
	int		i;

	if (!words[1])
		return (0);
	words[1] = concatenate(words);
	if (!words[1] || !check_colors_data(words[1]))
		return (0);
	colors = ft_split(words[1], ',');
	i = 0;
	while (i <= 2)
	{
		if (!colors[i] || ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
		{
			free_split(colors);
			return (0);
		}
		*(&((&game->floor + index - 6))->r + i) = ft_atoi(colors[i]);
		i++;
	}
	free_split(colors);
	return (1);
}
