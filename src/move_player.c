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
	if (game->map[game->player.pos.y / 64][(game->player.pos.x + game->player.delta.x * PLAYER_SIZE) / 64] != '1' && game->map[game->player.pos.y / 64][(game->player.pos.x + game->player.delta.x * PLAYER_SIZE) / 64] != '2')
		game->player.pos.x += game->player.delta.x;
	if (game->map[(game->player.pos.y + game->player.delta.y * PLAYER_SIZE) / 64][game->player.pos.x / 64] != '1' && game->map[(game->player.pos.y + game->player.delta.y * PLAYER_SIZE) / 64][game->player.pos.x / 64] != '2')
		game->player.pos.y += game->player.delta.y;
	// move_player(game, game->player.pos);
	return (0);
}

int		backward(t_game *game)
{
	if (game->map[game->player.pos.y / 64][(game->player.pos.x - game->player.delta.x * PLAYER_SIZE) / 64] != '1' && game->map[game->player.pos.y / 64][(game->player.pos.x - game->player.delta.x * PLAYER_SIZE) / 64] != '2')
		game->player.pos.x -= game->player.delta.x;
	if (game->map[(game->player.pos.y - game->player.delta.y * PLAYER_SIZE) / 64][game->player.pos.x / 64] != '1' && game->map[(game->player.pos.y - game->player.delta.y * PLAYER_SIZE) / 64][game->player.pos.x / 64] != '2')
		game->player.pos.y -= game->player.delta.y;
	// move_player(game, game->player.pos);
	return (0);
}

int		left(t_game *game)
{
	game->player.delta.x = cos(game->player.angle - M_PI_2) * SPEED;
	game->player.delta.y = sin(game->player.angle - M_PI_2) * SPEED;
	forward(game);
	game->player.delta.x = cos(game->player.angle) * SPEED;
	game->player.delta.y = sin(game->player.angle) * SPEED;
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
