/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:23:12 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 13:51:02 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Reproduit à l’identique le fonctionnement de la fonction strstr
**	(man strstr).
*/

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i] == to_find[j] && to_find[j] && str[i])
		{
			i++;
			j++;
		}
		if (j > 0 && j == (int)ft_strlen(to_find))
			return (&str[i - j]);
		else
			i -= j;
		i++;
	}
	return (0);
}
