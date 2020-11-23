/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:16:42 by agautier          #+#    #+#             */
/*   Updated: 2020/11/23 21:52:54 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_win(t_game *game)
{
	int	x;
	int	y;

	game->mlx.id = mlx_init();
	mlx_get_screen_size(game->mlx.id, &x, &y);
	if (game->res.x > x)
		game->res.x = x;
	if (game->res.y > y)
		game->res.y = y;
	game->mlx.win = mlx_new_window(game->mlx.id, game->res.x, game->res.y, "Cub3D");
}

int		close_win(t_game *game)
{
	printf("bye\n");
	free_textures(game);
	mlx_destroy_image(game->mlx.id, game->mlx.img.id);
	mlx_destroy_window(game->mlx.id, game->mlx.win);
	mlx_destroy_display(game->mlx.id);
	exit(0);
	return (0);
}
