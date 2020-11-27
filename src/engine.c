/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:35:27 by agautier          #+#    #+#             */
/*   Updated: 2020/11/23 20:3522 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_debug_dda(t_dda *dda)
{
	printf("\n-----\n");
	printf("nb_ray = %d\n", dda->nb_ray);
	printf("limit = %d\n", dda->limit);
	printf("dist_h = %f\n", dda->dist_h);
	printf("dist_v = %f\n", dda->dist_v);
	printf("map_pos.x = %d\n", dda->map_pos.x);
	printf("map_pos.y = %d\n", dda->map_pos.y);
	printf("ray.x = %f\n", dda->ray.x);
	printf("ray.y = %f\n", dda->ray.y);
	printf("ray.a = %f\n", dda->ray.a);
	printf("offset.x = %f\n", dda->offset.x);
	printf("offset.y = %f\n", dda->offset.y);
	printf("inter_h.x = %f\n", dda->inter_h.x);
	printf("inter_h.y = %f\n", dda->inter_h.y);
	printf("inter_v.x = %f\n", dda->inter_v.x);
	printf("inter_v.y = %f\n", dda->inter_v.y);
}

void	player(t_game *game, t_pos pos, int size, t_color c)
{
	game->player.pos.x = pos.x;
	game->player.pos.y = pos.y;
	game->player.size = size;
	game->player.color = c;
}

void	move_player(t_game *game, t_pos pos)
{
	if (pos.x + game->player.size / 2 <= game->res.x
			&& pos.x - game->player.size / 2 >= 0
			&& pos.y + game->player.size / 2 <= game->res.y
			&& pos.y - game->player.size / 2 >= 0)
	{
		draw_bg(game, game->bg_color);
		draw_map(game);
		player(game, game->player.pos, game->player.size, game->player.color);
		draw_player(game);
		raycaster(game);
		mlx_put_image_to_window(game->mlx.id, game->mlx.win, game->mlx.img.id,
				0, 0);
	}
}

double	dist(t_game *game, t_dpos inter)
{
	return (sqrt((inter.x - game->player.pos.x) * (inter.x - game->player.pos.x) + (inter.y - game->player.pos.y) * (inter.y - game->player.pos.y)));
}

void	dda_h_direction(t_game *game, t_dda *dda)
{
	double	atan;

	atan = -1 / tan(dda->ray.a);
	if (dda->ray.a > M_PI)
	{
		dda->ray.y = (((int)game->player.pos.y >> 6) << 6) - 0.0001;
		dda->ray.x = (game->player.pos.y - dda->ray.y) * atan
				+ game->player.pos.x;
		dda->offset.y = -64;
		dda->offset.x = -dda->offset.y * atan;
	}
	else if (dda->ray.a < M_PI)
	{
		dda->ray.y = (((int)game->player.pos.y >> 6) << 6) + 64;
		dda->ray.x = (game->player.pos.y - dda->ray.y) * atan
				+ game->player.pos.x;
		dda->offset.y = 64;
		dda->offset.x = -dda->offset.y * atan;
	}
	else
	{
		dda->ray.x = game->player.pos.x;
		dda->ray.y = game->player.pos.y;
		dda->limit = 8;
	}
}

void	dda_horizontal(t_game *game, t_dda *dda)
{
	int	mapX = 8;
	int	mapY = 8;
	const char	map[8][8] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};

	double	map_pos;

	dda->dist_h = 1000000;
	dda->limit = 0;
	dda_h_direction(game, dda);
	while (dda->limit < 8)
	{
		dda->map_pos.x = (int)dda->ray.x >> 6;
		dda->map_pos.y = (int)dda->ray.y >> 6;
		map_pos = dda->map_pos.y * mapX + dda->map_pos.x;	// mapX
		if (map_pos > 0 && map_pos < mapX * mapY
				&& map[dda->map_pos.y][dda->map_pos.x] == 1)	// Hit wall
		{
			dda->inter_h.x = dda->ray.x;
			dda->inter_h.y = dda->ray.y;
			dda->dist_h = dist(game, dda->inter_h);
			dda->limit = 8;
		}
		else
		{
			dda->ray.x += dda->offset.x;
			dda->ray.y += dda->offset.y;
			dda->limit += 1;
		}
	}
}

void	dda_v_direction(t_game *game, t_dda *dda)
{
	double	ntan;

	ntan = -tan(dda->ray.a);
	if (dda->ray.a > M_PI_2 && dda->ray.a < 3 * M_PI_2)
	{
		dda->ray.x = (((int)game->player.pos.x >> 6) << 6) - 0.0001;
		dda->ray.y = (game->player.pos.x - dda->ray.x) * ntan
				+ game->player.pos.y;
		dda->offset.x = -64;
		dda->offset.y = -dda->offset.x * ntan;
	}
	else if (dda->ray.a < M_PI_2 || dda->ray.a > 3 * M_PI_2)
	{
		dda->ray.x = (((int)game->player.pos.x >> 6) << 6) + 64;
		dda->ray.y = (game->player.pos.x - dda->ray.x) * ntan
				+ game->player.pos.y;
		dda->offset.x = 64;
		dda->offset.y = -dda->offset.x * ntan;
	}
	else
	{
		dda->ray.x = game->player.pos.x;
		dda->ray.y = game->player.pos.y;
		dda->limit = 8;
	}
}

void	dda_vertical(t_game *game, t_dda *dda)
{
	int	mapX = 8;
	int	mapY = 8;
	const char	map[8][8] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};
	double	map_pos;

	dda->dist_v = 1000000;
	dda->limit = 0;
	dda_v_direction(game, dda);
	while (dda->limit < 8)
	{
		dda->map_pos.x = (int)dda->ray.x >> 6;
		dda->map_pos.y = (int)dda->ray.y >> 6;
		map_pos = dda->map_pos.y * mapX + dda->map_pos.x;	// mapX
		if (map_pos > 0 && map_pos < mapX * mapY
				&& map[dda->map_pos.y][dda->map_pos.x] == 1)	// Hit wall
		{
			dda->inter_v.x = dda->ray.x;
			dda->inter_v.y = dda->ray.y;
			dda->dist_v = dist(game, dda->inter_v);
			dda->limit = 8;
		}
		else
		{
			dda->ray.x += dda->offset.x;
			dda->ray.y += dda->offset.y;
			dda->limit += 1;
		}
	}
}
// void	fov(t_game *game)
// {

// }

void	raycaster(t_game *game)
{
	t_dda	dda;
	t_color	col;
	double	distT;

	// dda.ray.a = game->player.angle;
	dda.ray.a = game->player.angle - 30 * DEG;
	dda.nb_ray = 0;
	while (dda.nb_ray < 60)
	{
		if (dda.ray.a < 0)
			dda.ray.a += 2 * M_PI;
		if (dda.ray.a > 2 * M_PI)
			dda.ray.a -= 2 * M_PI;
		dda_horizontal(game, &dda);
		dda_vertical(game, &dda);
		if (dda.dist_v < dda.dist_h)	// Vertical hit
		{
			dda.ray.x = dda.inter_v.x;
			dda.ray.y = dda.inter_v.y;
			distT = dda.dist_v;	// TODO:
			col = (t_color){187, 11, 11};
		}
		if (dda.dist_h < dda.dist_v)	// Horizontal hit
		{
			dda.ray.x = dda.inter_h.x;
			dda.ray.y = dda.inter_h.y;
			distT = dda.dist_h;	// TODO:
			col = (t_color){164, 36, 36};
		}
		// ft_debug_dda(&dda);
		draw_line(game, game->player.pos, (t_pos){dda.ray.x, dda.ray.y}, col);
		double ca = game->player.angle - dda.ray.a;
		if (ca < 0)
			ca += 2 * M_PI;
		if (ca > 2 * M_PI)
			ca -= 2 * M_PI;
		distT = distT * cos(ca);
		double lineH = (64 * 490) / distT;
		if (lineH > 490)
			lineH = 490;
		double lineO = 250 - lineH / 2;
		draw_line(game, (t_pos){dda.nb_ray*8+516, lineO}, (t_pos){dda.nb_ray*8+516, lineO + lineH}, col);
		draw_line(game, (t_pos){dda.nb_ray*8+516 + 1, lineO}, (t_pos){dda.nb_ray*8+516 + 1, lineO + lineH}, col);
		draw_line(game, (t_pos){dda.nb_ray*8+516 + 2, lineO}, (t_pos){dda.nb_ray*8+516 + 2, lineO + lineH}, col);
		draw_line(game, (t_pos){dda.nb_ray*8+516 + 3, lineO}, (t_pos){dda.nb_ray*8+516 + 3, lineO + lineH}, col);
		draw_line(game, (t_pos){dda.nb_ray*8+516 + 4, lineO}, (t_pos){dda.nb_ray*8+516 + 4, lineO + lineH}, col);
		draw_line(game, (t_pos){dda.nb_ray*8+516 + 5, lineO}, (t_pos){dda.nb_ray*8+516 + 5, lineO + lineH}, col);
		draw_line(game, (t_pos){dda.nb_ray*8+516 + 6, lineO}, (t_pos){dda.nb_ray*8+516 + 6, lineO + lineH}, col);
		draw_line(game, (t_pos){dda.nb_ray*8+516 + 7, lineO}, (t_pos){dda.nb_ray*8+516 + 7, lineO + lineH}, col);
		dda.nb_ray++;
		dda.ray.a += DEG;
	}
}

/*
	8	7	6	5		4	3	2	1
	0	0	0	0		0	0	0	0
	256	128	64	32		16	8	4	2

	512 -> 51.2 <- 512
*/
