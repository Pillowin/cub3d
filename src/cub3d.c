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
	game->dists = NULL;
}

int		main(int argc, char *argv[])
{
	t_game	game;

	//TODO: ne pas redimensionner la resolution si --save
	// TODO: changer les 64, les 8 et les >> 6 << 6 ? --> avec un define
	// TODO: gerer les sprites
	// TODO: revoir le parsing 
	// TODO: remplacer le calcul de racine carre									DONE
	// TODO: handle large and negative resolution									DONE
	// TODO: verifier que texture finit par .xpm et que 64x64						DONE
	// TODO: adapter la vitesse en fonction de la resolution
	/*
		DONE
		1: While raycasting the walls, store the perpendicular distance of each
		vertical stripe in a 1D ZBuffer

		DONE
		2: Calculate the distance of each sprite to the player

		DONE
		3: Use this distance to sort the sprites, from furthest away to closest
		to the camera

		TODO:
		4: Project the sprite on the camera plane (in 2D): subtract the player
		position from the sprite position, then multiply the result with the
		inverse of the 2x2 camera matrix

		TODO:
		5: Calculate the size of the sprite on the screen (both in x and y
		direction) by using the perpendicular distance

		TODO:
		6: Draw the sprites vertical stripe by vertical stripe, don't draw the
		vertical stripe if the distance is further away than the 1D ZBuffer of
		the walls of the current stripe

		TODO:
		7: Draw the vertical stripe pixel by pixel, make sure there's an
		invisible color or all sprites would be rectangles
	*/
	init_game(&game);
	game.mlx.id = mlx_init();
	global_parse(argv[1], &game);
	// printf("c = %d, %d, %d\n", game.ceiling.r, game.ceiling.g, game.ceiling.b);
	global_win(&game);
	global_event(&game);
	global_img(&game);
	// fprintf(stderr, "Map %s\n", argv[1]);
	if (argc == 2)
		mlx_loop(game.mlx.id);
	return (0);
}
