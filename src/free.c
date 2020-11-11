/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:16:39 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 22:20:31 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures(t_map *map)
{
	ft_free(map->north);
	ft_free(map->south);
	ft_free(map->west);
	ft_free(map->east);
	ft_free(map->sprite);
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
