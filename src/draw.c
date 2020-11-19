/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:24:07 by agautier          #+#    #+#             */
/*   Updated: 2020/11/19 23:37:26 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put_pixel(t_map *map, int x, int y, t_color c)
{
	map->mlx.img.data_addr[x * 4 + y * map->mlx.img.size_line + 0] = c.b;
	map->mlx.img.data_addr[x * 4 + y * map->mlx.img.size_line + 1] = c.g;
	map->mlx.img.data_addr[x * 4 + y * map->mlx.img.size_line + 2] = c.r;
	map->mlx.img.data_addr[x * 4 + y * map->mlx.img.size_line + 3] = 0;
}

void		put_square(t_map *map, t_pos pos, int size, t_color c)
{
	int	x;
	int	y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			put_pixel(map, pos.x + x, pos.y + y, c);
			x++;
		}
		y++;
	}
}

void		draw_bg(t_map *map, t_color c)
{
	int	x;
	int	y;

	map->bg_color = c;
	y = 0;
	while (y < map->res.y * map->mlx.img.size_line)
	{
		x = 0;
		while (x < map->mlx.img.size_line)
		{
			map->mlx.img.data_addr[x + y + 0] = c.b;
			map->mlx.img.data_addr[x + y + 1] = c.g;
			map->mlx.img.data_addr[x + y + 2] = c.r;
			map->mlx.img.data_addr[x + y + 3] = 0;
			x += 4;
		}
		y += map->res.x;
	}
}

void		draw_map(t_map *map)
{
	char	laby[8][8] =
	{
		{1,	1,	1,	1,	1,	1,	1,	1},
		{1,	0,	0,	1,	1,	0,	0,	1},
		{1,	0,	0,	1,	1,	0,	0,	1},
		{1,	0,	0,	0,	0,	0,	0,	1},
		{1,	0,	1,	0,	0,	0,	0,	1},
		{1,	0,	0,	0,	0,	0,	0,	1},
		{1,	0,	0,	0,	0,	0,	0,	1},
		{1,	1,	1,	1,	1,	1,	1,	1}
	};
	int	map_x = 8;
	int	map_y = 8;
	int	map_s = 64;
	int	x;
	int	y;

	y = 0;
	while (y < map_y)
	{
		x = 0;
		while (x < map_x)
		{
			if (laby[y][x])
				put_square(map, (t_pos){x * map_s, y * map_s}, map_s - 1,
						(t_color){255, 255, 255});
			else
				put_square(map, (t_pos){x * map_s, y * map_s}, map_s - 1,
						(t_color){0, 0, 0});
			x++;
		}
		y++;
	}
}

void		draw_player(t_map *map)
{
	t_pos	direction;

	direction.x = map->player.pos.x + cos(map->player.angle) * 21;
	direction.y = map->player.pos.y + sin(map->player.angle) * 21;
	put_square(map, (t_pos){map->player.pos.x - map->player.size / 2, map->player.pos.y - map->player.size / 2}, map->player.size, map->player.color);
	draw_line(map, map->player.pos, direction, map->player.color);
}

/*
**	Bresenham's line algorithm
*/

static void	draw_line_loop(t_map *map, t_draw_line dl)
{
	while (dl.a.x != dl.b.x || dl.a.y != dl.b.y)
	{
		put_pixel(map, dl.a.x, dl.a.y, dl.c);
		dl.e2 = dl.err;
		if (dl.e2 > -dl.d.x)
		{
			dl.err -= dl.d.y;
			dl.a.x += dl.s.x;
		}
		if (dl.e2 < dl.d.y)
		{
			dl.err += dl.d.x;
			dl.a.y += dl.s.y;
		}
	}
}

void		draw_line(t_map *map, t_pos a, t_pos b, t_color c)
{
	t_draw_line	dl;

	dl.a = a;
	dl.b = b;
	dl.c = c;
	dl.d.x = abs(dl.b.x - dl.a.x);
	if (dl.a.x < dl.b.x)
		dl.s.x = 1;
	else
		dl.s.x = -1;
	dl.d.y = abs(dl.b.y - dl.a.y);
	if (dl.a.y < dl.b.y)
		dl.s.y = 1;
	else
		dl.s.y = -1;
	if (dl.d.x > dl.d.y)
		dl.err = dl.d.x / 2;
	else
		dl.err = -dl.d.y / 2;
	draw_line_loop(map, dl);
}
