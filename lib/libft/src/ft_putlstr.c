/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:22:18 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:27:07 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Imprime les n premiers caracteres d'une chaine sur la sortie standard.
*/

void	ft_putlstr(const char *str, size_t n)
{
	size_t i;

	i = 0;
	while (str[i] && i < n)
	{
		write(1, &str[i], 1);
		i++;
	}
}
