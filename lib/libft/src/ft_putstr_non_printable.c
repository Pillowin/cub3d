/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:35:30 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 15:02:09 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				ft_is_printable(unsigned char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

static unsigned char	hexa_to_ascii(unsigned char c)
{
	if (c == 10)
		return ('a');
	else if (c == 11)
		return ('b');
	else if (c == 12)
		return ('c');
	else if (c == 13)
		return ('d');
	else if (c == 14)
		return ('e');
	else if (c == 15)
		return ('f');
	c += 48;
	return (c);
}

static void				write_non_printable(unsigned char c)
{
	char d0;
	char d1;

	d1 = hexa_to_ascii(c / 16);
	d0 = hexa_to_ascii(c % 16);
	write(1, &"\\", 1);
	write(1, &d1, 1);
	write(1, &d0, 1);
}

/*
**	Affiche une chaîne de caractères à l’écran.
**	Si cette chaînecontient des caractères non-imprimables, ils devront être
**	affichés sous forme hexa-décimale (en minuscules) en les précédant d’un
**	"backslash".
*/

void					ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_is_printable((unsigned char)str[i]))
			write_non_printable((unsigned char)str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
