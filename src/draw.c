/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiteer <gguiteer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:24:14 by mamaquig          #+#    #+#             */
/*   Updated: 2021/01/13 16:47:21by aagtetrer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_col_from_tex(t_game *game, t_dda *dda, int y)
{
	t_pos tex;
	unsigned int color;

	// TODO: changer la texture en fonction de la direction
	if (dda->dist_v < dda->dist_h)
		tex.x = fmod(dda->ray.y/64, 1) * game->north_data.res.x;
	else
		tex.x = fmod(dda->ray.x/64, 1) * game->north_data.res.x;
	tex.y = (y + (dda->line.y)/2.0 - game->res.y/2.0) * (game->north_data.res.y / (dda->line.y));
	color = *((unsigned int*)game->north_data.data_addr + (tex.y * game->north_data.res.x + tex.x));
	dda->col = (t_color){(color & 0xFF0000) >> 16, (color & 0x00FF00) >> 8, color & 0x0000FF};
}

void	draw_columns(t_game *game, t_dda *dda)
{
	int	y;

	y = 0;
	while (y < dda->line.x - 1)
	{
		put_pixel(game, dda->nb_ray, y, game->ceiling);
		put_pixel(game, dda->nb_ray, y + dda->line.x + dda->line.y, game->floor);
		y++;
	}
	while (y < dda->line.x + dda->line.y)
	{
		get_col_from_tex(game, dda, y);
		put_pixel(game, dda->nb_ray, y, dda->col);
		y++;
	}
}
