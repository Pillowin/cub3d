/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:24:07 by agautier          #+#    #+#             */
/*   Updated: 2020/11/23 20:38:33 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_bg(t_game *game, t_color c)
{
	int	x;
	int	y;

	game->bg_color = c;
	y = 0;
	while (y < game->res.y * game->mlx.img.size_line)
	{
		x = 0;
		while (x < game->mlx.img.size_line)
		{
			game->mlx.img.data_addr[x + y + 0] = c.b;
			game->mlx.img.data_addr[x + y + 1] = c.g;
			game->mlx.img.data_addr[x + y + 2] = c.r;
			game->mlx.img.data_addr[x + y + 3] = 0;
			x += 4;
		}
		y += game->res.x;
	}
}

void		draw_map(t_game *game)
{
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
	t_pos		size;
	int			x;
	int			y;

	size.x = 8;
	size.y = 8;
	y = 0;
	while (y < size.y)
	{
		x = 0;
		while (x < size.x)
		{
			if (map[y][x])
				put_square(game, (t_pos){x * size.x * size.y, y * size.x *
						size.y}, size.x * size.y - 1, (t_color){255, 255, 255});
			else
				put_square(game, (t_pos){x * size.x * size.y, y * size.x *
						size.y}, size.x * size.y - 1, (t_color){0, 0, 0});
			x++;
		}
		y++;
	}
}

void		draw_player(t_game *game)
{
	t_pos	pos;
	t_pos	direction;

	pos.x = game->player.pos.x - game->player.size / 2;
	pos.y = game->player.pos.y - game->player.size / 2;
	direction.x = game->player.pos.x + cos(game->player.angle) * 21;
	direction.y = game->player.pos.y + sin(game->player.angle) * 21;
	put_square(game, pos, game->player.size, game->player.color);
	draw_line(game, game->player.pos, direction, game->player.color);
}

/*
**	Bresenham's line algorithm
*/

static void	draw_line_loop(t_game *game, t_draw_line dl)
{
	while (dl.a.x != dl.b.x || dl.a.y != dl.b.y)
	{
		put_pixel(game, dl.a.x, dl.a.y, dl.c);
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

void		draw_line(t_game *game, t_pos a, t_pos b, t_color c)
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
	draw_line_loop(game, dl);
}
