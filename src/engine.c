/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:35:27 by agautier          #+#    #+#             */
/*   Updated: 2020/11/15 23:20:54 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_map *map, int x, int y)
{
	
}

void	draw_player(t_map *map, t_pos pos, int size, t_color c)
{
	int	x;
	int	y;
	t_player	player;
	t_game	game;

	printf("sizeof map = %lu\n", sizeof (t_map));
	printf("sizeof player = %lu\n", sizeof (t_player*));
	player.pos.x = pos.x;
	player.pos.y = pos.y;
	player.size = size;
	player.color = c;
	// map->player = &player;
	game.player = player;
	game.map = *map;
	y = pos.y - size / 2;
	while (y < pos.y + size / 2)
	{
		x = pos.x - size / 2;
		while (x < pos.x + size / 2)
		{
			put_pixel(map, x, y, c);
			x++;
		}
		y++;
	}
}
