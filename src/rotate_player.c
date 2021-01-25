/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:50:06 by mamaquig          #+#    #+#             */
/*   Updated: 2021/01/08 19:02:4 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_left(t_game *game)
{
	game->player.angle -= ROTATION_SPEED * DEG;
	if (game->player.angle < 0)
		game->player.angle += M_PI * 2;
	game->player.delta.x = cos(game->player.angle) * SPEED;
	game->player.delta.y = sin(game->player.angle) * SPEED;
	// move_player(game, game->player.pos);
	return (1);
}

int	rotate_right(t_game *game)
{
	game->player.angle += ROTATION_SPEED * DEG;
	if (game->player.angle > 2 * M_PI)
		game->player.angle -= M_PI * 2;
	game->player.delta.x = cos(game->player.angle) * SPEED;
	game->player.delta.y = sin(game->player.angle) * SPEED;
	// move_player(game, game->player.pos);
	return (1);
}
