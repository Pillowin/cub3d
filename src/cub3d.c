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
	// TODO: add tex_datas
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
}

int		main(int argc, char *argv[])
{
	t_game	game;

	//TODO: résolution à gérer quand trop petite et quand 0 quand --save
	//TODO: ne pas redimensionner la resolution si --save
	// TODO: handle large and negative resolution
	// TODO: changer les 64, les 8 et les >> 6 << 6 ? --> avec un define
	// TODO: remplacer le calcul de racine carre
	// TODO: gerer les sprites
	// TODO: revoir le parsing 
	// TODO: verifier que texture finit par .xpm
	init_game(&game);
	game.mlx.id = mlx_init();
	global_parse(argv[1], &game);
	global_win(&game);
	// init_textures(&game);
	global_event(&game);

	// init_textures(&game);

	global_img(&game);
	// fprintf(stderr, "Map %s\n", argv[1]);
	if (argc == 2)
		mlx_loop(game.mlx.id);
	return (0);
}
