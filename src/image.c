/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:17:22 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 17:05:25 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_img(t_map *map)
{
	int	x;
	int	y;

	map->res.x = 800;
	map->res.y = 800;
	map->mlx.img.bpp = 32;
	map->mlx.img.size_line = map->res.x;
	map->mlx.img.endian = 0;
	map->mlx.img.id = mlx_new_image(map->mlx.id, map->res.x, map->res.y);
	map->mlx.img.data_addr = mlx_get_data_addr(map->mlx.img.id,
		&map->mlx.img.bpp, &map->mlx.img.size_line, &map->mlx.img.endian);
	y = 0;
	while (y < map->res.y * map->mlx.img.size_line)
	{
		x = 0;
		while (x < map->mlx.img.size_line)
		{
			map->mlx.img.data_addr[x + y + 0] = (char)0;
			map->mlx.img.data_addr[x + y + 1] = (char)0;
			map->mlx.img.data_addr[x + y + 2] = (char)255;
			map->mlx.img.data_addr[x + y + 3] = (char)0;
			x += 4;
		}
		y += map->res.x;
	}
	mlx_put_image_to_window(map->mlx.id, map->mlx.win, map->mlx.img.id, 0, 0);
}
