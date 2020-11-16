/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:10:07 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 13:57:17 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min_case(int base_len, int *nbr)
{
	int carry;

	if (*nbr == -2147483648)
	{
		carry = -(*nbr % base_len);
		*nbr = -(*nbr / base_len);
		ft_putchar('-');
		return (carry);
	}
	return (-1);
}

static int	ft_is_base_err(char *base, int base_len)
{
	int i;
	int j;

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
**	Fonction qui affiche un nombre dans le terminal dans une base donnée.
*/

void		ft_putnbr_base(int nbr, char *base)
{
	int base_len;
	int carry;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (ft_is_base_err(base, base_len))
		return ;
	carry = ft_min_case(base_len, &nbr);
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
	}
	if (nbr >= 0 && nbr < base_len)
		ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base(nbr / base_len, base);
		ft_putnbr_base(nbr % base_len, base);
		if (carry >= 0)
			ft_putchar(base[carry]);
	}
}
