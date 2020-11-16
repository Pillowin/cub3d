/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:40:55 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:12:14 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Ajoute l’élément new à la fin de la liste.
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (!alst[0])
	{
		alst[0] = new;
		return ;
	}
	lst = alst[0];
	while (lst->next)
		lst = lst->next;
	lst->next = new;
}
