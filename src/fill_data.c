/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:43:59 by agautier          #+#    #+#             */
/*   Updated: 2021/01/14 16:21:114 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			fill_resolution(t_game *game, char **words, int index)
{
	(void)index;
	if (!words[2])
		return (0);
	game->res.x = ft_atoi(words[1]);
	game->res.y = ft_atoi(words[2]);
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
	if (fd == -1)
	{
		set_error(game, ERR_TEXTURE);
		ft_error(game);
	}
	close(fd);
	tex_data.bpp = -1;
	tex_data.size_line = -1;
	tex_data.endian = -1;
	tex_data.res.x = 0;
	tex_data.res.y = 0;
	tex_data.id = mlx_xpm_file_to_image(game->mlx.id, words[1], &tex_data.res.x, &tex_data.res.y);
	tex_data.data_addr = mlx_get_data_addr(tex_data.id, &tex_data.bpp, &tex_data.size_line, &tex_data.endian);
	*(&game->north_data + (index - 1)) = tex_data;

	// printf("res x = %d\n", tex_data.res.x);
	// printf("res y = %d\n", tex_data.res.y);
	// printf("size_line = %d\n", tex_data.size_line);
	// printf("bpp = %d\n", tex_data.bpp);
	// printf("endian = %d\n\n", tex_data.endian);
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
		tmp = ft_strjoin(cols, words[i]);
		ft_free(cols);
		cols = tmp;
		i++;
	}
	ft_free(words[1]);
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
	if (!check_colors_data(words[1]))
		return (0);
	colors = ft_split(words[1], ',');
	i = 0;
	while (i <= 2)
	{
		if (ft_atoi(colors[i]) < 0 || ft_atoi(colors[i]) > 255)
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
