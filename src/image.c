/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiteer <gguiteer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:16:58 by mamaquig          #+#    #+#             */
/*   Updated: 2021/01/11 1600::117 byagattierr         ###   ########.fr       */
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

void	global_img(t_game *game)
{
	game->mlx.img = init_img(game);
	// draw_bg(game, game->ceiling, game->floor);
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

	// MINIMAP
	ft_disp_minimap(game);

	mlx_put_image_to_window(game->mlx.id, game->mlx.win, game->mlx.img.id, 0, 0);
}
