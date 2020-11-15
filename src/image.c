/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:17:22 by agautier          #+#    #+#             */
/*   Updated: 2020/11/15 23:06:15 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	get_texture(t_map *map)
// {
// 	int	x;
// 	int	y;

// 	x = map->res.x;
// 	y = map->res.y;
// 	map->mlx.img.id = mlx_xpm_file_to_image(map->mlx.id, map->north, &x, &y);
// 	y = 0;
// 	while (y < 10)
// 	{
// 		x = 0;
// 		while (x < 10)
// 		{
// 			mlx_put_image_to_window(map->mlx.id, map->mlx.win, map->mlx.img.id,
// 			x * 64, y * 64);
// 			x += 1;
// 		}
// 		y += 1;
// 	}
// }

void	put_pixel(t_map *map, int x, int y, t_color c)
{
	map->mlx.img.data_addr[x * 4 + y * map->mlx.img.size_line + 0] = c.b;
	map->mlx.img.data_addr[x * 4 + y * map->mlx.img.size_line + 1] = c.g;
	map->mlx.img.data_addr[x * 4 + y * map->mlx.img.size_line + 2] = c.r;
	map->mlx.img.data_addr[x * 4 + y * map->mlx.img.size_line + 3] = (char)0;
}

void	global_img(t_map *map)
{
	int	x;
	int	y;

	// get_texture(map);
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
			map->mlx.img.data_addr[x + y + 0] = (char)76;
			map->mlx.img.data_addr[x + y + 1] = (char)76;
			map->mlx.img.data_addr[x + y + 2] = (char)76;
			map->mlx.img.data_addr[x + y + 3] = (char)0;
			x += 4;
		}
		y += map->res.x;
	}
	draw_player(map, (t_pos){300, 300}, 8, (t_color){255, 255, 0});
	mlx_put_image_to_window(map->mlx.id, map->mlx.win, map->mlx.img.id, 0, 0);
}
