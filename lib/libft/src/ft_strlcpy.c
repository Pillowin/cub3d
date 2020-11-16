/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:56:35 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 13:59:47 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	man strlcpy
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		src_len;

	if (!dest && !src)
		return (0);
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size < 1)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
