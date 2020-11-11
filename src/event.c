/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:07:40 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 22:23:04 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_event(t_map *map)
{
	mlx_key_hook(map->mlx.win, event_hook, map);
	mlx_mouse_hook(map->mlx.win, event_hook, map);
	mlx_hook(map->mlx.win, DESTROY_NOTIFY, STRUCTURE_NOTIFY_MASK,
			close_win, map);
	mlx_hook(map->mlx.win, VISIBILITY_NOTIFY, VISIBILITY_CHANGE_MASK,
			minimise_hook, map);
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
	printf("%d\n", keycode);
	return (0);
}
