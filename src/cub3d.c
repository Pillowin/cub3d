/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:40:06 by mamaquig          #+#    #+#             */
/*   Updated: 2021/01/08 18:17:220 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_game(t_game *game)
{
	// TODO: add tex_datas and sprite
	game->mlx = (t_mlx){NULL, NULL, (t_img){NULL, NULL, 0, 0, 0, (t_pos){0, 0}}};
	game->map = NULL;
	game->res = (t_res){0, 0};
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->sprite = NULL;
	game->north_data = (t_img){NULL, NULL, 0, 0, 0, (t_pos){0, 0}};
	game->south_data = (t_img){NULL, NULL, 0, 0, 0, (t_pos){0, 0}};
	game->west_data = (t_img){NULL, NULL, 0, 0, 0, (t_pos){0, 0}};
	game->east_data = (t_img){NULL, NULL, 0, 0, 0, (t_pos){0, 0}};
	game->sprite_data = (t_img){NULL, NULL, 0, 0, 0, (t_pos){0, 0}};
	game->floor = (t_color){0, 0, 0};
	game->ceiling = (t_color){0, 0, 0};
	game->player = (t_player){
		(t_pos){0, 0},
		(t_pos){0, 0},
		0.0,
		0,
		(t_key){0, 0, 0, 0, 0, 0},
		(t_color){0, 0, 0}
	};
	game->err = 0;
	game->dists = NULL;
}

int		main(int argc, char *argv[])
{
	t_game	game;

	// TODO: Gérer les leaks
	// TODO: changer les 64, les 8 et les >> 6 << 6 ? --> avec un define
	// TODO: gerer les sprites
	// TODO: revoir le parsing
	// TODO: adapter la vitesse en fonction de la resolution
	// TODO: verifier que le 2e argument est bien un .cub
	// TODO: ptete checker les appels inutiles a find_max 
	// TODO: ne pas redimensionner la resolution si --save							DONE
	// TODO: remplacer le calcul de racine carre									DONE
	// TODO: handle large and negative resolution									DONE
	// TODO: verifier que texture finit par .xpm et que 64x64						DONE

	init_game(&game);
	if (argc == 2)
	{
		game.mlx.id = mlx_init();
		global_parse(argv[1], &game);
		global_img(&game);
		global_win(&game);
		global_event(&game);
		mlx_loop(game.mlx.id);
	}
	else if (argc == 3 && (!ft_strncmp(argv[2], "--save", 7) || !ft_strncmp(argv[2], "-s", 3)))
	{
		game.mlx.id = mlx_init();
		global_parse(argv[1], &game);
		global_img(&game);
		ft_create_bmp(&game);
		free_game(&game);
	}
	else
	{
		set_error(&game, ERR_ARG);
		ft_error(&game);
	}
	return (0);
}
