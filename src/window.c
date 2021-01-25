/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:16:40 by mamaquig          #+#    #+#             */
/*   Updated: 2021/01/18 22:00:42 by mamaquig         ###   ########.fr       */
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
	if (game->res.y <= 0 || game->res.x <= 0)
	{
		set_error(game, ERR_DATA);
		ft_error(game);
	}
	game->mlx.win = mlx_new_window(game->mlx.id, game->res.x, game->res.y, "Cub3D");
}

int		close_win(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}
