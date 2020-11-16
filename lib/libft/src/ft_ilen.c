/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:28:51 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:23:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Contre les digits d'un nombre (le - n'est pas compté).
*/

int	ft_ilen(int n)
{
	int len;

	len = 1;
	while (n > 9 || n < -9)
	{
		len++;
		n /= 10;
	}
	return (len);
}
