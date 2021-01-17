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

double	dist(t_game *game, t_dpos inter)
{
	return (sqrt((inter.x - game->player.pos.x) * (inter.x - game->player.pos.x) + (inter.y - game->player.pos.y) * (inter.y - game->player.pos.y)));
}

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
