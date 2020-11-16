/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:05:34 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 12:46:29 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	return 0 means no flag
**	return 1 means flag '-' is used
**	return 2 means flag '0' is used
*/

static int	ft_handle_flags(t_directive *dir, const char *str)
{
	if (dir->flags_end - dir->flags_start)
	{
		if (ft_strlchr(&str[dir->flags_start], '-',
			dir->flags_end - dir->flags_start))
			return (1);
		if (ft_strlchr(&str[dir->flags_start], '0',
			dir->flags_end - dir->flags_start))
			return (2);
	}
	return (0);
}

static int	ft_handle_width(va_list ap, t_directive *dir, const char *str)
{
	int	width;

	width = 0;
	if (ft_strlchr(&str[dir->width_start], '*',
		dir->width_end - dir->width_start))
		width = va_arg(ap, int);
	else if (dir->width_end - dir->width_start > 0)
		width = ft_latoi(&str[dir->width_start],
			dir->width_end - dir->width_start);
	return (width);
}

static int	ft_handle_precision(va_list ap, t_directive *dir, const char *str)
{
	int	precision;

	precision = 0;
	if (str[dir->precision_start] != '.')
		return (0);
	if (ft_strlchr(&str[dir->precision_start + 1], '*',
		dir->precision_end - dir->precision_start + 1))
		precision = va_arg(ap, int);
	else if (dir->precision_end - dir->precision_start > 0)
		precision = ft_latoi(&str[dir->precision_start + 1],
			dir->precision_end - dir->precision_start + 1);
	return (precision);
}

/*
**	t[0] -> flags
**	t[1] -> width
**	t[2] -> precision
**	t[3] -> digit length
**	t[4] -> printed
*/

static int	ft_handle_return(t_directive *dir, long nbr, int t[5])
{
	if (t[1] && (!t[0]))
		ft_print_spaces(t[1] - t[4] - (t[2] && t[2] > t[3] ? t[2] : t[3]));
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (t[1] && t[0] == 2)
		ft_print_zeros(t[1] - t[4] - (t[2] ? t[2] : t[3]));
	if (t[2] > t[3])
		ft_print_zeros(t[2] - t[3]);
	if (t[2] || dir->precision_end - dir->precision_start == 0 ||
		!(!nbr && !t[2] && dir->precision_end - dir->precision_start >= 1))
		ft_putlnbr(nbr);
	if (t[1] && t[0] == 1)
		ft_print_spaces(t[1] - t[4] - (t[2] && t[2] > t[3] ? t[2] : t[3]));
	if (t[2] > t[3] && (!t[1] || t[2] >= t[1]))
		t[4] += t[2];
	else if (t[1] > t[3])
		t[4] = t[1];
	else
		t[4] += t[3];
	return (t[4]);
}

int			ft_print_int(va_list ap, t_directive *dir, const char *str)
{
	long	nbr;
	int		t[5];

	t[0] = ft_handle_flags(dir, str);
	if ((t[1] = ft_handle_width(ap, dir, str)) < 0)
	{
		t[1] = -t[1];
		t[0] = 1;
	}
	t[2] = ft_handle_precision(ap, dir, str);
	nbr = va_arg(ap, int);
	if (!nbr && (dir->precision_end - dir->precision_start == 1 ||
		(dir->precision_end - dir->precision_start > 1 && !t[2])))
		t[3] = 0;
	else
		t[3] = ft_ilen(nbr);
	t[4] = nbr < 0 ? 1 : 0;
	if (t[0] == 2 && dir->precision_end - dir->precision_start > 0 && t[2] >= 0)
		t[0] = 0;
	if (t[2] < 0 && nbr)
		t[2] = 0;
	else if (t[2] < 0 && !nbr)
		t[2] = 1;
	return (ft_handle_return(dir, nbr, t));
}
