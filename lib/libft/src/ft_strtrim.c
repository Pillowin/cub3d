/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:58:06 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:09:52 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_char(char const *s1, char const *set)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (s1[i] && ft_is_set(s1[i], set))
	{
		c++;
		i++;
	}
	i = ft_strlen(s1) - 1;
	while (c != i + 1 && ft_is_set(s1[i], set))
	{
		c++;
		i--;
	}
	return (c);
}

/*
**	Alloue (avec malloc(3)) et retourne une copie dela chaine ’s1’, sans les
**	caractères spécifiésdans ’set’ au début et à la fin de la chaine de
**	caractères.
*/

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		s1_len;
	int		set_count;
	int		i;
	int		j;

	if (!s1 || !set)
		return (0);
	s1_len = ft_strlen(s1);
	set_count = ft_count_char(s1, set);
	if (!(ptr = (char *)malloc(sizeof(char) * (s1_len - set_count) + 1)))
		return (0);
	i = 0;
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	set_count -= i;
	j = 0;
	while (s1[i] && i < s1_len - set_count)
		ptr[j++] = s1[i++];
	ptr[j] = '\0';
	return (ptr);
}
