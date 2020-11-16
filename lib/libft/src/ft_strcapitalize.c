/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:43:53 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 13:45:58 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Met en majuscule la première lettre de chaque mot et le reste du mot en
**	minuscule.
**	Un mot est une suite de caractères alphanumériques.
*/

char		*ft_strcapitalize(char *str)
{
	int	i;

	if (ft_isalpha(str[0]) && ft_islower(str[0]))
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_isupper(str[i]))
			str[i] += 32;
		if (!ft_isalpha(str[i - 1]) && !ft_isdigit(str[i - 1])
				&& ft_isalpha(str[i]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
