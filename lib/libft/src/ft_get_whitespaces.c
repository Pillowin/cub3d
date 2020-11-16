/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_whitespaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:43:14 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:22:53 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Renvoie une chaine contenant tous les whitespaces.
*/

char	*ft_get_whitespaces(void)
{
	return ("\t\n\v\f\r ");
}
