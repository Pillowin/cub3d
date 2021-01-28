/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:22:00 by agautier          #+#    #+#             */
/*   Updated: 2021/01/28 15:28:12 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	init_img(t_game *game)
{
	t_img img;

	img.bpp = 32;
	img.size_line = game->res.x;
	img.endian = 0;
	img.id = mlx_new_image(game->mlx.id, game->res.x, game->res.y);
	img.data_addr = mlx_get_data_addr(img.id, &img.bpp, &img.size_line,
										&img.endian);
	return (img);
}

void	global_img(t_game *game, int save)
{
	int x;
	int y;

	if (!save)
	{
		mlx_get_screen_size(game->mlx.id, &x, &y);
		if (game->res.x > x)
			game->res.x = x;
		if (game->res.y > y)
			game->res.y = y;
	}
	game->mlx.img = init_img(game);
	init_dda(game);
	game->dists = (double *)malloc(sizeof(game->dists) * game->res.x);
	if (!game->dists)
	{
		set_error(game, ERR_MALLOC);
		ft_error(game);
	}
	init_player(game);
	raycaster(game);
	find_sprites(game);
	calc_dist_sprite(game);
	fill_visibility(game);
	draw_sprite(game);
}
