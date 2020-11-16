/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:43:14 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 15:02:27 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Renvoie 1 si le caractère passé en paramètre est une lettre minuscule
**	et renvoie 0 si le caractère passé en paramètre est un autre type de
**	caractère.
*/

int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
