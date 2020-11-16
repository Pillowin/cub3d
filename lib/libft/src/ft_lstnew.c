/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:02:47 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:19:52 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue (avec malloc(3)) et renvoie un nouvel élément.
**	la variable content est initialisée àl’aide de la valeur du paramètre
**	content.
**	La variable ’next’ est initialisée à NULL.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	if (!(ptr = malloc((sizeof(content) + sizeof(t_list *)))))
		return (0);
	ptr->content = content;
	ptr->next = 0;
	return (ptr);
}
