/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:51:05 by agautier          #+#    #+#             */
/*   Updated: 2021/01/27 13:51:06 by agautier         ###   ########.fr       */
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
