/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:07:37 by mamaquig          #+#    #+#             */
/*   Updated: 2021/01/18 16:58:2 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_columns(t_game *game, t_dda *dda)
{
	int				y;
	int				tex_id;
	int				tex_x;
	int				tex_y;
	unsigned int	color;

	if (dda->ray.a >= 0 && dda->ray.a < M_PI && dda->dist_v > dda->dist_h)
		tex_id = 1;	// South
	else if (dda->ray.a >= M_PI_2 && dda->ray.a < 3 * M_PI_2 && dda->dist_v < dda->dist_h)
		tex_id = 2;	// West
	else if (dda->dist_v < dda->dist_h)
		tex_id = 3;	// East
	else
		tex_id = 0;	// North

	if (dda->dist_v < dda->dist_h)
		tex_x = fmod(dda->ray.y / 64, 1) * (&game->north_data + tex_id)->res.x;
	else
		tex_x = fmod(dda->ray.x / 64, 1) * (&game->north_data + tex_id)->res.x;

	if (tex_id == 1 || tex_id == 2)
		tex_x = 64 - tex_x;

	y = 0;
	while (y < dda->line.x)
	{
		put_pixel(game, dda->nb_ray, y, game->ceiling);
		put_pixel(game, dda->nb_ray, y + dda->line.x + dda->line.y, game->floor);
		y++;
	}
	while (y < game->res.y - dda->line.x)
	{
		tex_y = (y + dda->line.y / 2 - game->res.y / 2) * ((&game->north_data + tex_id)->res.y / dda->line.y);
		color = *((unsigned int*)((&game->north_data + tex_id)->data_addr) + (tex_y * (&game->north_data + tex_id)->res.x + tex_x));
		dda->col = (t_color){(color & 0xFF0000) >> 16, (color & 0x00FF00) >> 8, color & 0x0000FF};
		put_pixel(game, dda->nb_ray, y, dda->col);
		y++;
	}
}
