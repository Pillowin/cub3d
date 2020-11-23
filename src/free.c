/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:16:39 by agautier          #+#    #+#             */
/*   Updated: 2020/11/20 18:03:00 by agautier         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (words[i])
	{
		ft_free(words[i]);
		i++;
	}
	ft_free(words);
}
