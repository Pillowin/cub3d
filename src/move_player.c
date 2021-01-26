/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:28:24 by agautier          #+#    #+#             */
/*   Updated: 2021/01/26 14:35:28 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		forward(t_game *game)
{
	t_pos	posx;
	t_pos	posy;

	posx.x = (game->player.pos.x + game->player.delta.x * PLAYER_SIZE) / 64;
	posx.y = game->player.pos.y / 64;
	posy.x = game->player.pos.x / 64;
	posy.y = (game->player.pos.y + game->player.delta.y * PLAYER_SIZE) / 64;
	if (game->map[posx.y][posx.x] != '1' && game->map[posx.y][posx.x] != '2')
		game->player.pos.x += game->player.delta.x;
	if (game->map[posy.y][posy.x] != '1' && game->map[posy.y][posy.x] != '2')
		game->player.pos.y += game->player.delta.y;
	return (0);
}

int		backward(t_game *game)
{
	t_pos	posx;
	t_pos	posy;

	posx.x = (game->player.pos.x - game->player.delta.x * PLAYER_SIZE) / 64;
	posx.y = game->player.pos.y / 64;
	posy.x = game->player.pos.x / 64;
	posy.y = (game->player.pos.y - game->player.delta.y * PLAYER_SIZE) / 64;
	if (game->map[posx.y][posx.x] != '1' && game->map[posx.y][posx.x] != '2')
		game->player.pos.x -= game->player.delta.x;
	if (game->map[posy.y][posy.x] != '1' && game->map[posy.y][posy.x] != '2')
		game->player.pos.y -= game->player.delta.y;
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
