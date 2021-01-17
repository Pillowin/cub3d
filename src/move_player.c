/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:46:13 by agautier          #+#    #+#             */
/*   Updated: 2021/01/08 19:4837 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		forward(t_game *game)
{
	game->player.pos.x += game->player.delta.x;
	game->player.pos.y += game->player.delta.y;
	move_player(game, game->player.pos);
	return (0);
}

int		backward(t_game *game)
{
	game->player.pos.x -= game->player.delta.x;
	game->player.pos.y -= game->player.delta.y;
	move_player(game, game->player.pos);
	return (0);
}

int		left(t_game *game)
{
	// TODO: DO
	// printf("%d %d\n", game->player.delta.x, game->player.delta.y);
	// printf("%d %d %f\n", game->player.pos.x, game->player.pos.y, game->player.angle * RAD);
	game->player.delta.x = cos(game->player.angle - M_PI_2) * SPEED;
	game->player.delta.y = sin(game->player.angle - M_PI_2) * SPEED;
	forward(game);
	game->player.delta.x = cos(game->player.angle) * SPEED;
	game->player.delta.y = sin(game->player.angle) * SPEED;
	// 0 <= angle <= 2pi
	// if (angle * 180 / M_PI)
	// {
	// 	game->player.pos.x -= game->player.delta.y;
	// 	game->player.pos.y -= game->player.delta.x;
	// }
	// else if (angle  * 180 / M_PI)
	// {
	// 	game->player.pos.x -= game->player.delta.y;
	// 	game->player.pos.y -= game->player.delta.x;
	// }
	// move_player(game, game->player.pos);
	return (0);
}

int		right(t_game *game)
{
	game->player.delta.x = cos(game->player.angle + M_PI_2) * SPEED;
	game->player.delta.y = sin(game->player.angle + M_PI_2) * SPEED;
	forward(game);
	game->player.delta.x = cos(game->player.angle) * SPEED;
	game->player.delta.y = sin(game->player.angle) * SPEED;
	return (0);
}
