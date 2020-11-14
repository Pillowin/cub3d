/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:17:22 by agautier          #+#    #+#             */
/*   Updated: 2020/11/14 17:42:52 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(t_map *map)
{
	int	x;
	int	y;

	map->mlx.img.id = mlx_xpm_file_to_image(map->mlx.id, map->north, &map->res.x, &map->res.y);
	y = 0;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			mlx_put_image_to_window(map->mlx.id, map->mlx.win, map->mlx.img.id,
			x * 64, y * 64);
			x += 1;
		}
		y += 1;
	}


}

void	global_img(t_map *map)
{
	// int	x;
	// int	y;

	get_texture(map);
	// map->mlx.img.bpp = 32;
	// map->mlx.img.size_line = map->res.x;
	// map->mlx.img.endian = 0;
	// map->mlx.img.id = mlx_new_image(map->mlx.id, map->res.x, map->res.y);
	// map->mlx.img.data_addr = mlx_get_data_addr(map->mlx.img.id,
	// 	&map->mlx.img.bpp, &map->mlx.img.size_line, &map->mlx.img.endian);
	// y = 0;
	// while (y < map->res.y * map->mlx.img.size_line)
	// {
	// 	x = 0;
	// 	while (x < map->mlx.img.size_line)
	// 	{
	// 		map->mlx.img.data_addr[x + y + 0] = (char)0;
	// 		map->mlx.img.data_addr[x + y + 1] = (char)0;
	// 		map->mlx.img.data_addr[x + y + 2] = (char)255;
	// 		map->mlx.img.data_addr[x + y + 3] = (char)0;
	// 		x += 4;
	// 	}
	// 	y += map->res.x;
	// }
	// mlx_put_image_to_window(map->mlx.id, map->mlx.win, map->mlx.img.id, 0, 0);
}
