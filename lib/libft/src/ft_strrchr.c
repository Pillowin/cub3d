/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:48:47 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:00:50 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	man strrchr
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			res = ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		res = ((char *)&s[i]);
	return (res);
}
