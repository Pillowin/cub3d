/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:17:22 by agautier          #+#    #+#             */
/*   Updated: 2020/11/19 23:31:40 by agautier         ###   ########.fr       */
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

t_img	init_img(t_map *map)
{
	t_img	img;

	img.bpp = 32;
	img.size_line = map->res.x;
	img.endian = 0;
	img.id = mlx_new_image(map->mlx.id, map->res.x, map->res.y);
	img.data_addr = mlx_get_data_addr(img.id,
		&img.bpp, &img.size_line, &img.endian);
	return (img);
}

void	img_cpy(t_map *map, char *dest, char *src)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->res.y * map->mlx.img.size_line)
	{
		x = 0;
		while (x < map->mlx.img.size_line)
		{
			dest[x + y] = src[x + y];
			x += 4;
		}
		y += map->res.x;
	}
}

void	global_img(t_map *map)
{
	// get_texture(map);
	map->mlx.img = init_img(map);
	draw_bg(map, (t_color){76, 76, 76});
	draw_map(map);
	player(map, (t_pos){300, 300}, 9, (t_color){255, 255, 0});
	map->player.angle = 0;
	map->player.delta = (t_pos){cos(map->player.angle) * 5, sin(map->player.angle) * 5};
	draw_player(map);
	mlx_put_image_to_window(map->mlx.id, map->mlx.win, map->mlx.img.id, 0, 0);
}
