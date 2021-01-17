/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 19:40:13 by agautier          #+#    #+#             */
/*   Updated: 2021/001/06 17:444:49 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_game *game, t_dda *dda)
{
	if (dda->ray.a < 0)
		dda->ray.a += 2 * M_PI;
	if (dda->ray.a > 2 * M_PI)
		dda->ray.a -= 2 * M_PI;
	dda_horizontal(game, dda);
	dda_vertical(game, dda);
	find_intersection(dda);
	dda->cos_angle = game->player.angle - dda->ray.a;
	if (dda->cos_angle < 0)
		dda->cos_angle += 2 * M_PI;
	if (dda->cos_angle > 2 * M_PI)
		dda->cos_angle -= 2 * M_PI;
	dda->dist_t = dda->dist_t * cos(dda->cos_angle);
	dda->line.y = (64 * game->res.y) / dda->dist_t;
	if (dda->line.y > game->res.y)
		dda->line.y = game->res.y;
	dda->line.x = game->res.y / 2 - dda->line.y / 2;
}

void	raycaster(t_game *game)
{
	t_dda	dda;

	find_max(game, &(dda.max.x), &(dda.max.y));
	dda.ray.a = game->player.angle - FOV / 2 * DEG;
	dda.nb_ray = 0;
	while (dda.nb_ray < game->res.x)
	{
		raycast(game, &dda);
		draw_columns(game, &dda);
		dda.ray.a += FOV * DEG / game->res.x;
		if (dda.ray.a > 2 * M_PI)
			dda.ray.a -= 2 * M_PI;
		dda.nb_ray++;
	}
}
