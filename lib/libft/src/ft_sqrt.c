/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:48:55 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 14:05:42 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Renvoie la racine carrée entière d’un nombre si elle existe, 0 si la
**	racine carrée n’est pas entière.
*/

int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i < 46341)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
