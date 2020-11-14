/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:13:12 by agautier          #+#    #+#             */
/*   Updated: 2020/11/14 19:27:53 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

map
{
	{1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 1, 0, 1},
	{1, 0, 0, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 'N', 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1}
};

void	raycast(t_map *map)
{

	struct point
	{
		x;
		y;
	};

	struct cam
	{
		hauteur_cam
		orientation cam
		fov
		posCamX et posCamY
	};

	ecran de projection size

}

distance	detection_mur_horizontal()
distance	detection_mur_vertical()

calcul_hauteur_colonne()

