/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:38:10 by agautier          #+#    #+#             */
/*   Updated: 2021/01/29 16:10:49 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_left(t_game *game)
{
	game->player.angle -= game->rota_speed * DEG;
	if (game->player.angle < 0)
		game->player.angle += M_PI * 2;
	game->player.delta.x = cos(game->player.angle) * game->speed;
	game->player.delta.y = sin(game->player.angle) * game->speed;
	return (1);
}

int	rotate_right(t_game *game)
{
	game->player.angle += game->rota_speed * DEG;
	if (game->player.angle > 2 * M_PI)
		game->player.angle -= M_PI * 2;
	game->player.delta.x = cos(game->player.angle) * game->speed;
	game->player.delta.y = sin(game->player.angle) * game->speed;
	return (1);
}
