/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:07:40 by agautier          #+#    #+#             */
/*   Updated: 2020/11/19 23:35:51 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_event(t_map *map)
{
	mlx_hook(map->mlx.win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK,
			close_win, map);
	mlx_hook(map->mlx.win, VISIBILITY_NOTIFY, VISIBILITY_CHANGE_MASK,
			minimise_hook, map);
	mlx_hook(map->mlx.win, KEY_PRESS, KEY_PRESS_MASK, event_hook, map);
}

int		minimise_hook(t_map *map)
{
	mlx_put_image_to_window(map->mlx.id, map->mlx.win, map->mlx.img.id, 0, 0);
	return (0);
}

int		event_hook(int keycode, t_map *map)
{
	if (keycode == ESC_KEY)
		close_win(map);
	else if (keycode == W_KEY)
	{
		map->player.pos.x += map->player.delta.x;
		map->player.pos.y += map->player.delta.y;
		move_player(map, map->player.pos);
	}
	else if (keycode == A_KEY)
	{
		map->player.angle -= 0.3;
		if (map->player.angle < 0)
			map->player.angle += 2 * M_PI;
		map->player.delta.x = cos(map->player.angle) * 5;
		map->player.delta.y = sin(map->player.angle) * 5;
		move_player(map, map->player.pos);

	}
	else if (keycode == S_KEY)
	{
		map->player.pos.x -= map->player.delta.x;
		map->player.pos.y -= map->player.delta.y;
		move_player(map, map->player.pos);
	}
	else if (keycode == D_KEY)
	{
		map->player.angle += 0.3;
		if (map->player.angle > 2 * M_PI)
			map->player.angle -= 2 * M_PI;
		map->player.delta.x = cos(map->player.angle) * 5;
		map->player.delta.y = sin(map->player.angle) * 5;
		move_player(map, map->player.pos);
	}
	printf("angle = %f\n", map->player.angle);
	printf("delta.x = %d\n", map->player.delta.x);
	printf("delta.y = %d\n", map->player.delta.y);
	printf("pos.x = %d\n", map->player.pos.x);
	printf("pos.y = %d\n\n", map->player.pos.y);
	return (0);
}
