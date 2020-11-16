/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:52:53 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 14:04:21 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Fonction récursive qui renvoie la factorielle du nombre passé en paramètre.
*/

int	ft_recursive_factorial(int nb)
{
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	nb *= ft_recursive_factorial(nb - 1);
	return (nb);
}
