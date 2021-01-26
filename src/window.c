/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:46:33 by agautier          #+#    #+#             */
/*   Updated: 2021/01/26 16:47:02 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_win(t_game *game)
{
	int x;
	int y;

	mlx_get_screen_size(game->mlx.id, &x, &y);
	if (game->res.x > x)
		game->res.x = x;
	if (game->res.y > y)
		game->res.y = y;
	game->mlx.win = mlx_new_window(game->mlx.id, game->res.x,
			game->res.y, TITLE);
	mlx_put_image_to_window(game->mlx.id, game->mlx.win,
			game->mlx.img.id, 0, 0);
}

int		close_win(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
