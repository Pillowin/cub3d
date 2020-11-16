/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 21:23:19 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 13:18:19 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Divise les int pointés par a et b.
**	Le résultat de la division est stocké dans l’int pointé par a.
**	Le résultat du reste de la division est stocké dans l’int pointé par b.
*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int tmp;

	tmp = *a / *b;
	*b = *a % *b;
	*a = tmp;
}
