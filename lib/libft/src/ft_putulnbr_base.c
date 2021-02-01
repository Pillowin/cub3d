/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 12:41:39 by agautier          #+#    #+#             */
/*   Updated: 2021/01/30 17:07:32 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_base_err(char *base, unsigned long base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base_len < 2)
		return (1);
	while (base[i])
	{
		if ((base[i] == '\t' || base[i] == '\n' || base[i] == '\v' ||
					base[i] == '\f' || base[i] == '\r' || base[i] == ' ' ||
					base[i] == '-' || base[i] == '+'))
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
**	Voir ft_putnbr_base mais avec un unsigned long en parametre.
*/

void		ft_putulnbr_base(unsigned long n, char *base, int *printed, int fd)
{
	unsigned long	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (ft_is_base_err(base, base_len))
		return ;
	if (n < base_len)
	{
		ft_putchar_fd(base[n], fd);
		*printed = *printed + 1;
	}
	else
	{
		ft_putulnbr_base(n / base_len, base, printed, fd);
		ft_putulnbr_base(n % base_len, base, printed, fd);
	}
}
