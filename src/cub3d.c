/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:35:29 by agautier          #+#    #+#             */
/*   Updated: 2021/01/28 15:27:19 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char *argv[])
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc == 2 && check_cub(&game, argv[1]))
	{
		game.mlx.id = mlx_init();
		global_parse(argv[1], &game);
		global_img(&game, 0);
		global_win(&game);
		global_event(&game);
		mlx_loop(game.mlx.id);
	}
	else if (argc == 3 && check_cub(&game, argv[1]) &&
		(!ft_strncmp(argv[2], "--save", 7) || !ft_strncmp(argv[2], "-s", 3)))
	{
		game.mlx.id = mlx_init();
		global_parse(argv[1], &game);
		global_img(&game, 1);
		ft_create_bmp(&game);
		free_game(&game);
		exit(EXIT_SUCCESS);
	}
	set_error(&game, ERR_ARG);
	ft_error(&game);
	return (0);
}
