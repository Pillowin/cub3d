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

double	dist(double ax, double ay, double bx, double by, double ang)
{
	(void)ang;
	return (sqrt((bx-ax) * (bx-ax) + (by-ay) * (by-ay)));
}

void	raycaster(t_game *game)
{
	int	r;
	int	mx;
	int	my;
	int	mp;
	int	dof;
	double	rx;
	double	ry;
	double	ra;
	double	xo;
	double	yo;
	double	atan;
	double	ntan;
	double	distH = 1000000;
	double	hx = game->player.pos.x;
	double	hy = game->player.pos.y;
	double	distV = 1000000;
	double	vx = game->player.pos.x;
	double	vy = game->player.pos.y;
	int	mapX = 8;
	int	mapY = 8;
	t_color	col;
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

	ra = game->player.angle;
	r = 0;
	while (r < 1)
	{
		// Horizontal lines
		dof = 0;
		atan = -1 / tan(ra);
		if (ra > M_PI)	// Looking down
		{
			ry = (((int)game->player.pos.y >> 6) << 6) - 0.0001;
			rx = (game->player.pos.y - ry) * atan + game->player.pos.x;
			yo = -64;
			xo = -yo * atan;
		}
		if (ra < M_PI)	// Looking up
		{
			ry = (((int)game->player.pos.y >> 6) << 6) + 64;
			rx = (game->player.pos.y - ry) * atan + game->player.pos.x;
			yo = 64;
			xo = -yo * atan;
		}
		if (ra == 0 || ra == M_PI)	// Looking straight left or right
		{
			rx = game->player.pos.x;
			ry = game->player.pos.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)rx >> 6;
			my = (int)ry >> 6;
			mp = my * mapX + mx;	// mapX
			if (mp > 0 && mp < mapX * mapY && map[my][mx] == 1)	// Hit wall
			{
				hx = rx;
				hy = ry;
				distH = dist(game->player.pos.x, game->player.pos.y, hx, hy, game->player.angle);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}

		// Vertical lines
		dof = 0;
		ntan = -tan(ra);
		if (ra > M_PI_2 && ra < 3 * M_PI_2)	// Looking left
		{
			rx = (((int)game->player.pos.x >> 6) << 6) - 0.0001;
			ry = (game->player.pos.x - rx) * ntan + game->player.pos.y;
			xo = -64;
			yo = -xo * ntan;
		}
		if (ra < M_PI_2 || ra > 3 * M_PI_2)	// Looking right
		{
			rx = (((int)game->player.pos.x >> 6) << 6) + 64;
			ry = (game->player.pos.x - rx) * ntan + game->player.pos.y;
			xo = 64;
			yo = -xo * ntan;
		}
		if (ra == 0 || ra == M_PI)	// Looking straight up or down
		{
			rx = game->player.pos.x;
			ry = game->player.pos.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)rx >> 6;
			my = (int)ry >> 6;
			mp = my * mapX + mx;	// mapX
			if (mp > 0 && mp < mapX * mapY && map[my][mx] == 1)	// Hit wall
			{
				vx = rx;
				vy = ry;
				distV = dist(game->player.pos.x, game->player.pos.y, vx, vy, game->player.angle);
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		r++;
		if (distV < distH)	// Vertical hit
		{
			rx = vx;
			ry = vy;
			col = (t_color){255, 0, 0};
		}
		if (distH < distV)	// Horizontal hit
		{
			rx = hx;
			ry = hy;
			col = (t_color){0, 255, 0};
		}
		draw_line(game, game->player.pos, (t_pos){rx, ry}, col);
		// draw_line(game, game->player.pos, (t_pos){rx, ry}, (t_color){0, 255, 0});
		r++;
	}
}

/*
	8	7	6	5		4	3	2	1
	0	0	0	0		0	0	0	0
	256	128	64	32		16	8	4	2

	512 -> 51.2 <- 512
*/
