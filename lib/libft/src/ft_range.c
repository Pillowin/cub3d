/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:54:09 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 15:03:02 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Retourne un tableau d’int.
**	Ce tableau d’int contiendra toutes les valeurs entre min et max.
*/

int	*ft_range(int min, int max)
{
	int *ptr;
	int i;
	int j;

	if (min >= max)
		return ((int *)0);
	if (!(ptr = (int *)malloc(sizeof(int) * (max - min))))
		return ((int *)0);
	i = min;
	j = 0;
	while (i < max)
	{
		ptr[j] = i;
		j++;
		i++;
	}
	return (ptr);
}
