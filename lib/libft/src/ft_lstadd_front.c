/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:42:08 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:12:41 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Ajoute l’élément ’new’ au début de la liste.
*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = alst[0];
	alst[0] = new;
}
