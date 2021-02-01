/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:59:51 by agautier          #+#    #+#             */
/*   Updated: 2021/02/01 20:30:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Libère la mémoire de l’élément passé en argumenten utilisant la fonction
**	del puis avec free(3).
**	La mémoire de next n'est pas free.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		// free(lst);
		ft_free((void **)&lst);
	}
}
