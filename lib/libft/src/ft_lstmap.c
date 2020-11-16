/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:48:24 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:18:54 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Itère sur la liste lst et applique la fonction f au contenu de chaque
**	élément.
**	Crée une nouvelle liste résultant des applications successives de f.
**	La fonction del est la pour detruire le contenu d'un élément si nécessaire.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*fnew_lst;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	if (!(new_lst = ft_lstnew(f(lst->content))))
		return (0);
	fnew_lst = new_lst;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&fnew_lst, del);
			return (0);
		}
		new_lst->next = tmp;
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (fnew_lst);
}
