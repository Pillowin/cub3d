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

t_color	get_col_from_tex(t_game *game)
{
	// Savoir si c'est une intersection horizontale ou verticale
	// position du ray en x et y
	(void)game;

	// OBJECTIF: determiner le pixel interessant dans la texture => tex_x et tex_y
	return (
		((t_color){255, 255, 255})
		// Le rgb correspondant au pixel trouve en fonction de la position du rayon
	);
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
		dda->col = get_col_from_tex(game);
		put_pixel(game, dda->nb_ray, y, dda->col);
		y++;
	}
}
