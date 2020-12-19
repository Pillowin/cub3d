/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:50:26 by agautier          #+#    #+#             */
/*   Updated: 2020/11/28 18:25:09 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	fill_resolution(t_game *game, char **words, int index)
{
	if (!words[2])
		return (0);
	(void)index;
	game->res.x = ft_atoi(words[1]);
	game->res.y = ft_atoi(words[2]);
	return (1);
}

int	fill_texture(t_game *game, char **words, int index)
{
	if (!words[1])
		return (0);
	*(&game->north + index - 1) = ft_strdup(words[1]);
	return (1);
}

int	fill_color(t_game *game, char **words, int index)
{
	char	**colors;
	int		i;

	if (!words[1])
		return (0);
	colors = ft_split(words[1], ',');
	i = 0;
	while (i <= 2)
	{
		*(&((&game->floor + index - 6)->r) + i) = ft_atoi(colors[i]);
		ft_free(colors[i]);
		i++;
	}
	ft_free(colors);
	return (1);
}
