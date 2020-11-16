/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:32:05 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 13:18:09 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Échange le contenu de deux entiers dont les adresses sont données en
**	paramètres.
*/

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}
