/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:19:51 by mamaquig          #+#    #+#             */
/*   Updated: 2021/01/14 16:49:556 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_game *game)
{
	ft_free(game->north);
	ft_free(game->south);
	ft_free(game->west);
	ft_free(game->east);
	ft_free(game->sprite);
}

void	free_split(char **words)
{
	int index;

	index = 0;
	while (words[index])
	{
		ft_free(words[index]);
		index++;
	}
	ft_free(words);
}


// TODO: free sprites
void	free_game(t_game *game)
{
	if (game->mlx.id)
	{
		mlx_loop_end(game->mlx.id);
		if (game->mlx.img.id)
			mlx_destroy_image(game->mlx.id, game->mlx.img.id);
		if (game->north_data.id)
			mlx_destroy_image(game->mlx.id, game->north_data.id);
		if (game->south_data.id)
			mlx_destroy_image(game->mlx.id, game->south_data.id);
		if (game->west_data.id)
			mlx_destroy_image(game->mlx.id, game->west_data.id);
		if (game->east_data.id)
			mlx_destroy_image(game->mlx.id, game->east_data.id);
		if (game->sprite_data.id)
			mlx_destroy_image(game->mlx.id, game->sprite_data.id);
		if (game->mlx.win)
			mlx_destroy_window(game->mlx.id, game->mlx.win);
		mlx_destroy_display(game->mlx.id);
		ft_free(game->mlx.id);
	}
	if (game->map)
		free_split(game->map);
	if (game->north)
		ft_free(game->north);
	if (game->south)
		ft_free(game->south);
	if (game->west)
		ft_free(game->west);
	if (game->east)
		ft_free(game->east);
	if (game->sprite)
		ft_free(game->sprite);
}
