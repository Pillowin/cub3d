/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:22:42 by agautier          #+#    #+#             */
/*   Updated: 2020/12/19 20:22:43 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	t_game	game;

	global_parse(argv[1], &game);
	global_win(&game);
	global_event(&game);
	global_img(&game);

	// fprintf(stderr, "Map %s\n", argv[1]);

	if (argc == 2)
		mlx_loop(game.mlx.id);
	return (0);
}
