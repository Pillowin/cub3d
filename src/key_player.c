/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:08:06 by agautier          #+#    #+#             */
/*   Updated: 2020/11/24 22:11:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	forward(t_game *game)
{
	game->player.pos.x += game->player.delta.x;
	game->player.pos.y += game->player.delta.y;
	move_player(game, game->player.pos);
	return (1);
}

int	backward(t_game *game)
{
	game->player.pos.x -= game->player.delta.x;
	game->player.pos.y -= game->player.delta.y;
	move_player(game, game->player.pos);
	return (1);
}

int	left(t_game *game)
{
	game->player.angle -= 0.2;
	if (game->player.angle < 0)
		game->player.angle += 2 * M_PI;
	game->player.delta.x = cos(game->player.angle) * 5;
	game->player.delta.y = sin(game->player.angle) * 5;
	move_player(game, game->player.pos);
	return (1);
}

int	right(t_game *game)
{
	game->player.angle += 0.2;
	if (game->player.angle > 2 * M_PI)
		game->player.angle -= 2 * M_PI;
	game->player.delta.x = cos(game->player.angle) * 5;
	game->player.delta.y = sin(game->player.angle) * 5;
	move_player(game, game->player.pos);
	return (1);
}
