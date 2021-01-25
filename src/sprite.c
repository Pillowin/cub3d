/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:49:22 by agautier          #+#    #+#             */
/*   Updated: 2021/01/20 17:05:3 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	int count_sprites(t_game *game)
{
	int nb_sprite;
	int	x;
	int	y;
	int	max_x;
	int max_y;

	find_max(game, &max_x, &max_y);
	nb_sprite = 0;
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			if (x < (int)ft_strlen(game->map[y]) && game->map[y][x] == '2')
			{
				nb_sprite++;
			}
			x++;
		}
		y++;
	}
	return (nb_sprite);
}

static void	sort_sprites(t_game *game)
{
	int i;
	t_sprite tmp;

	i = 0;
	while (i < count_sprites(game) - 1)
	{
		if (game->sprites[i].dist < game->sprites[i + 1].dist && (i + 1) < (count_sprites(game)))
		{
			tmp = game->sprites[i];
			game->sprites[i] = game->sprites[i + 1];
			game->sprites[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	find_sprites(t_game *game)
{
	int	x;
	int	y;
	int	max_x;
	int max_y;
	int	nb_sprite;

	find_max(game, &max_x, &max_y);
	nb_sprite = count_sprites(game);
	game->sprites = (t_sprite *)malloc(sizeof(*game->sprites) * nb_sprite);
	if (!game->sprites)
	{
		set_error(game, ERR_MALLOC);
		ft_error(game);
	}
	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			if (x < (int)ft_strlen(game->map[y]) && game->map[y][x] == '2')
			{
				game->sprites[nb_sprite - 1] = (t_sprite){(t_pos){x * 64 + 32, y * 64 + 32}, 0.0, 0};
				nb_sprite--;
			}
			x++;
		}
		y++;
	}
}

void	calc_dist_sprite(t_game *game)
{
	int	i;

	// printf("nb_sprites = %d\n", count_sprites(game));
	i = 0;
	while (i < count_sprites(game))
	{
		game->sprites[i].dist = 
			sqrt(
				(game->player.pos.x - game->sprites[i].pos.x) * (game->player.pos.x - game->sprites[i].pos.x) + 
				(game->player.pos.y - game->sprites[i].pos.y) * (game->player.pos.y - game->sprites[i].pos.y)
			);
		// printf("sprite %d dist = %f\n", i, game->sprites[i].dist);
		i++;
	}
	sort_sprites(game);
	// i = 0;
	// while (i < count_sprites(game))
	// {
	// 	printf("sprite %d dist = %f\n", i, sqrt(game->sprites[i].dist) * 64.0);
	// 	i++;
	// }
}

void	fill_visibility(t_game *game)
{
	int	i;
	double	angle_player_sprite;
	double	delta_angle;

	i = 0;
	while (i < count_sprites(game))
	{
		angle_player_sprite = atan2(game->sprites[i].pos.y - game->player.pos.y, game->sprites[i].pos.x - game->player.pos.x);

		delta_angle = game->player.angle - angle_player_sprite;
		if (delta_angle > 2 * M_PI)
			delta_angle -= 2 * M_PI;
		else if (delta_angle < 0)
			delta_angle += 2 * M_PI;

		if (delta_angle < FOV / 2 * DEG || delta_angle > 2 * M_PI - FOV / 2 * DEG)
			game->sprites[i].visible = 1;
		else
			game->sprites[i].visible = 0;
		i++;
	}

	// i = 0;
	// while (i < count_sprites(game))
	// {
	// 	if (game->sprites[i].visible)
	// 		printf("VISIBLE !!\n");
	// 	else
	// 		printf("invisible\n");
	// 	i++;
	// }
	// printf("\n");
}

void	draw_sprite(t_game *game)
{
	int		sprite_curr;
	double	side;
	int		y_begin;
	int		y_curr;
	int		x_begin;
	int		x_curr;
	double	col_width;
	t_color col;
	unsigned int color;

	sprite_curr = 0;
	while (sprite_curr < count_sprites(game))
	{
		if (game->sprites[sprite_curr].visible)
		{
			side = 64 / game->sprites[sprite_curr].dist * (game->res.x / 2) / tan(FOV / 2 * DEG);
	// dda->line.y = (64 * game->res.y) / dda->dist_t;
	// dda->line.x = game->res.y / 2 - dda->line.y / 2;
			// y_begin = game->res.y / 2 - (int)side / 2;
			y_begin = game->res.y - (game->res.y / 2 - ((64 * game->res.y) / game->sprites[sprite_curr].dist)) - side - side / 2;
			col_width = side / 64.0;
			x_begin = 
				(game->res.x / 2) / tan(FOV / 2 * DEG) * 
				tan(
					atan2(
						game->player.pos.y - game->sprites[sprite_curr].pos.y,
						game->player.pos.x - game->sprites[sprite_curr].pos.x
					) - game->player.angle
				) + (game->res.x / 2.0) - (side / 2);
			x_curr = x_begin;
			while (x_curr < x_begin + (int)side)
			{
				if (x_curr >= 0 &&
					x_curr < game->res.x &&
					game->sprites[sprite_curr].dist < game->dists[x_curr])
				{
					y_curr = y_begin;
					while (y_curr < y_begin + side)
					{
						color = *((unsigned int*)(game->sprite_data.data_addr) + ((int)((y_curr - y_begin) / col_width) * game->sprite_data.res.x) + (int)((x_curr - x_begin) / col_width));
						if (color && x_curr >= 0 && x_curr < game->res.x && y_curr >= 0 && y_curr < game->res.y)
						{
							col = (t_color){(color & 0xFF0000) >> 16, (color & 0x00FF00) >> 8, color & 0x0000FF};
							put_pixel(game, x_curr, y_curr, col);
						}
						y_curr++;
					}
				}
				x_curr++;
			}
		}
		sprite_curr++;
	}
}
