/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:11:50 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 15:02:51 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue et assigne un tableau d’int.
**	Ce tableau d’int contiendra toutes les valeurs entre min et max.
*/

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int j;

	if (min >= max)
	{
		range[0] = 0;
		return (0);
	}
	if (!(range[0] = (int *)malloc(sizeof(int) * (max - min))))
		return (-1);
	i = min;
	j = 0;
	while (i < max)
	{
		range[0][j] = i;
		j++;
		i++;
	}
	return (max - min);
}
