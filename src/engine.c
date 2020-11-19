/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 21:35:27 by agautier          #+#    #+#             */
/*   Updated: 2020/11/19 22:15:42 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_color	get_color(t_map *map, int x, int y)
// {
// 	char	r;
// 	int	g;
// 	int	b;
// 	char *c;
// 	printf("map->mlx.img.data_addr = %p\n", map->mlx.img.data_addr);
// 	r = (char)*(map->mlx.img.data_addr);
// 	c = map->mlx.img.data_addr;
// 	printf("c = %s\n", c);
// 	printf("c.r = %d\n", c[0]);
// 	printf("r = %d\n", r);
// 	printf("data_addr = %s\n", map->mlx.img.data_addr);
// 	g = x;
// 	b = y;
// 	return ((t_color){0, g, b});
// }

void	player(t_map *map, t_pos pos, int size, t_color c)
{
	map->player.pos.x = pos.x;
	map->player.pos.y = pos.y;
	map->player.size = size;
	map->player.color = c;
}

void	move_player(t_map *map, t_pos pos)
{
	if (pos.x + map->player.size / 2 <= map->res.x
			&& pos.x - map->player.size / 2 >= 0
			&& pos.y + map->player.size / 2 <= map->res.y
			&& pos.y - map->player.size / 2 >= 0)
	{
		printf("On bouge !\n");
		printf("angle = %f\n", map->player.angle);
		printf("delta.x = %d\n", map->player.delta.x);
		printf("delta.y = %d\n", map->player.delta.y);
		printf("pos.x = %d\n", map->player.pos.x);
		printf("pos.y = %d\n\n", map->player.pos.y);
		draw_bg(map, map->bg_color);
		draw_map(map);
		player(map, map->player.pos, map->player.size, map->player.color);
		draw_player(map);
		mlx_put_image_to_window(map->mlx.id, map->mlx.win, map->mlx.img.id, 0, 0);
	}
}
