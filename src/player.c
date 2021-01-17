/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:15:43 by mamaquig          #+#    #+#             */
/*   Updated: 2021/01/13 17:08:41 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_game *game)
{
	if (game->map[game->player.pos.y][game->player.pos.x] == 'N')
		game->player.angle = -M_PI_2;
	else if (game->map[game->player.pos.y][game->player.pos.x] == 'S')
		game->player.angle = M_PI_2;
	else if (game->map[game->player.pos.y][game->player.pos.x] == 'W')
		game->player.angle = M_PI;
	else if (game->map[game->player.pos.y][game->player.pos.x] == 'E')
		game->player.angle = 0;
	game->player.pos = (t_pos){game->player.pos.x * 64 + 32, game->player.pos.y * 64 + 32};
	game->player.delta = (t_pos){cos(game->player.angle) * SPEED, sin(game->player.angle) * SPEED};
}

void	move_player(t_game *game, t_pos pos)
{
	if (pos.x <= game->res.x && pos.x >= 0 && pos.y <= game->res.y && pos.y >= 0)	// Colisions avec la fentre
	{
		// draw_bg(game, game->ceiling, game->floor);
		// draw_map(game);
		game->player.pos = pos;
		// player(game, game->player.pos, game->player.size, game->player.color);
		// draw_player(game);
		raycaster(game);
		mlx_put_image_to_window(game->mlx.id, game->mlx.win, game->mlx.img.id,
				0, 0);
	}
}
