/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:52:15 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:00:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	man strnstr
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = 0;
	while (needle[needle_len] != '\0')
		needle_len++;
	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && needle[j] && haystack[i] && i < len)
		{
			i++;
			j++;
		}
		if (j > 0 && j == needle_len)
			return ((char *)&haystack[i - j]);
		else
			i -= j;
		i++;
	}
	return (0);
}
