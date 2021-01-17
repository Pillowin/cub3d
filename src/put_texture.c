/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:28:23 by mamaquig          #+#    #+#             */
/*   Updated: 2020/12/28 18:24:30 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put_pixel(t_game *game, int x, int y, t_color c)
{
	game->mlx.img.data_addr[x * 4 + y * game->mlx.img.size_line + 0] = c.b;
	game->mlx.img.data_addr[x * 4 + y * game->mlx.img.size_line + 1] = c.g;
	game->mlx.img.data_addr[x * 4 + y * game->mlx.img.size_line + 2] = c.r;
	game->mlx.img.data_addr[x * 4 + y * game->mlx.img.size_line + 3] = (char)0;
}

void		put_square(t_game *game, t_pos pos, int size, t_color c)
{
	int y;
	int x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			put_pixel(game, pos.x + x, pos.y + y, c);
			x++;
		}
		y++;
	}
}
