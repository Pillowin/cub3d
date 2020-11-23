/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:39:31 by agautier          #+#    #+#             */
/*   Updated: 2020/11/20 18:03:00 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc < 2)
	{
		perror("Utilise 1 argument !\n");
		return (1);
	}
	printf("%s\n", argv[1]);
	global_parse(argv[1], &game);
	global_win(&game);
	global_img(&game);
	global_event(&game);
	mlx_loop(game.mlx.id);
	return (0);
}
