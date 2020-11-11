/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:16:42 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 22:26:37 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_win(t_map *map)
{
	map->mlx.id = mlx_init();
	map->mlx.win = mlx_new_window(map->mlx.id, 800, 800, "titre");
}

int		close_win(t_map *map)
{
	free_textures(map);
	mlx_destroy_image(map->mlx.id, map->mlx.img.id);
	mlx_destroy_window(map->mlx.id, map->mlx.win);
	exit(0);
	return (1);
}
