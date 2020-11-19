/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:16:42 by agautier          #+#    #+#             */
/*   Updated: 2020/11/18 16:53:51 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_win(t_map *map)
{
	int	x;
	int	y;

	map->mlx.id = mlx_init();
	mlx_get_screen_size(map->mlx.id, &x, &y);
	if (map->res.x > x)
		map->res.x = x;
	if (map->res.y > y)
		map->res.y = y;
	map->mlx.win = mlx_new_window(map->mlx.id, map->res.x, map->res.y, "Cub3D");
}

int		close_win(t_map *map)
{
	printf("bye\n");
	free_textures(map);
	mlx_destroy_image(map->mlx.id, map->mlx.img.id);
	mlx_destroy_window(map->mlx.id, map->mlx.win);
	exit(0);
	return (1);
}
