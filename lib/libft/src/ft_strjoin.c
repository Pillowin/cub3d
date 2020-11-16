/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:56:01 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:08:00 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Alloue (avec malloc(3)) et retourne une nouvelle chaine, résultat de la
**	concaténation de s1 et s2.
*/

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s1_len;
	int		s2_len;
	int		i;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	i = 0;
	while (i < s1_len)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		ptr[s1_len + i] = s2[i];
		i++;
	}
	ptr[s1_len + s2_len] = '\0';
	return (ptr);
}
