/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:39:31 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 23:01:20 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc < 2)
	{
		perror("Utilise 1 argument !\n");
		return (1);
	}
	global_parse(argv[1], &map);
	global_win(&map);
	global_event(&map);
	global_img(&map);
	mlx_loop(map.mlx.id);
	return (0);
}
