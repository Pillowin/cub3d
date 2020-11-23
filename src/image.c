/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:17:22 by agautier          #+#    #+#             */
/*   Updated: 2020/11/20 18:03:00 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	init_img(t_game *game)
{
	t_img	img;

	img.bpp = 32;
	img.size_line = game->res.x;
	img.endian = 0;
	img.id = mlx_new_image(game->mlx.id, game->res.x, game->res.y);
	img.data_addr = mlx_get_data_addr(img.id,
		&img.bpp, &img.size_line, &img.endian);
	return (img);
}

void	global_img(t_game *game)
{
	game->mlx.img = init_img(game);
	player(game, (t_pos){300, 300}, 9, (t_color){255, 255, 0});
	game->player.angle = 0;
	game->player.delta.x = cos(game->player.angle) * 5;
	game->player.delta.y = sin(game->player.angle) * 5;
	draw_bg(game, (t_color){76, 76, 76});
	draw_map(game);
	draw_player(game);
	mlx_put_image_to_window(game->mlx.id, game->mlx.win, game->mlx.img.id, 0, 0);
}
