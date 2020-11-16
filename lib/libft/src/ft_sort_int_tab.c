/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:28:43 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 13:18:04 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Trie un tableau d’entiers par ordre croissant.
**	Les paramètres sont un pointeur sur entier et le nombre d’entiers dans le
**	tableau.
*/

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1] && (i + 1) < (size))
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}
