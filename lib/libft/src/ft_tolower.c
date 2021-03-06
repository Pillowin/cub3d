/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:19:49 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:01:02 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	man tolower
*/

int	ft_tolower(int c)
{
	if (c < 'A' || c > 'Z')
		return (c);
	return (c + 32);
}
