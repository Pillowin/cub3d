/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:40:04 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 13:17:58 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Inverse l’ordre des élements d’un tableau d’entiers.
**	Les paramètres sont un pointeur sur entier et le nombre d’entiers dans le
**	tableau.
*/

void	ft_rev_int_tab(int *tab, int size)
{
	int tmp[size];
	int i;

	i = 0 - 1;
	while (i++ < size - 1)
		tmp[i] = tab[size - i - 1];
	i = 0 - 1;
	while (i++ < size - 1)
		tab[i] = tmp[i];
}
