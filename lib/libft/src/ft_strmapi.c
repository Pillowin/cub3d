/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:57:05 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:08:56 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Applique la fonction ’f’ à chaque caractère de la chaine de caractères
**	passée en argument pour créer une nouvelle chaine de caractères
**	(avec malloc(3)) résultant des applications successives de ’f’.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	while (s[i])
		i++;
	if (!(ptr = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
