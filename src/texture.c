/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:44:44 by agautier          #+#    #+#             */
/*   Updated: 2021/01/14 15:09:557 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_game *game)
{
	int	x;
	int	y;
	t_pos	bmp_res;
	t_img	bmp;

	unsigned int *colors;

	bmp.bpp = -1;
	bmp.size_line = -1;
	bmp.endian = -1;
	bmp.id = mlx_xpm_file_to_image(game->mlx.id, game->north, &bmp_res.x, &bmp_res.y);
	bmp.data_addr = mlx_get_data_addr(bmp.id, &bmp.bpp, &bmp.size_line, &bmp.endian);

	printf("img res x = %d\n", bmp_res.x);
	printf("img res y = %d\n", bmp_res.y);

	printf("bmp.size_line = %d\n", bmp.size_line);
	printf("bmp.bpp = %d\n", bmp.bpp);
	printf("bmp.endian = %d\n", bmp.endian);

	colors = (unsigned int*)bmp.data_addr;
	printf("colors[0] = %d\n", colors[0]);
	// printf("img[0] = %d\n", mlx_get_color_value(game->mlx.id, img[0]));
	// printf("img[1] = %d\n", img[1]);
	// printf("img[2] = %d\n", img[2]);

	// 00000000 00000000 00000001 00010000

	x = 200;
	y = 200;
	mlx_put_image_to_window(game->mlx.id, game->mlx.win, bmp.id, x, y);

	// sleep(5);	// TODO: remove
	exit(1);
}
