/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:13:15 by agautier          #+#    #+#             */
/*   Updated: 2021/01/11 17:14:4:32 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_tex_type(char *words)
{
	char *texture_type;
	char *texture;

	texture_type = ".xpm";
	texture = *(&words) + (ft_strlen(words) - 4);
	if (ft_strncmp(texture, texture_type, 4))
		return (1);
	return (0);
}

double	dist(t_game *game, t_dda *dda, t_dpos inter)
{
	return (cos((dda->ray.a)) * (inter.x - game->player.pos.x) + sin((dda->ray.a)) * (inter.y - game->player.pos.y));
}

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
