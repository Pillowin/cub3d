/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:08:00 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 12:46:10 by agautier         ###   ########.fr       */
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
**	t[0] is flags
**	t[1] is width
**	t[2] is precision
**	t[3] is printed
**	t[4] is ret
*/

static int	ft_handle_return(t_directive *dir, unsigned int nbr,
char *base, int t[5])
{
	if (t[0] == 2 && t[1] && t[2] && t[2] > 0)
		ft_print_spaces(t[2] > t[3] ? t[1] - t[2] : t[1] - t[3]);
	else if (t[0] == 2 && t[1] && t[2])
		ft_print_zeros(t[2] > t[3] ? t[1] - t[2] : t[1] - t[3]);
	else if (t[0] == 2 && t[1] && (dir->precision_start < dir->precision_end))
		ft_print_spaces(t[1] - t[3]);
	else if (t[0] == 2 && t[1])
		ft_print_zeros(t[1] - t[3]);
	if (t[2] > t[3])
		ft_print_zeros(t[2] - t[3]);
	t[3] = 0;
	if (nbr || t[2] || dir->precision_start == dir->precision_end)
		ft_putunbr_base(nbr, base, &t[3], STDOUT_FILENO);
	else if (t[0] != 1)
		ft_print_spaces(1);
	if (t[0] == 1)
		ft_print_spaces(t[2] && t[2] > t[3] ? t[1] - t[2] : t[1] - t[3]);
	if (t[2] > t[3] && t[2] > t[1])
		t[4] = t[2];
	else if (t[1] > t[3])
		t[4] = t[1];
	else
		t[4] = t[3];
	return (t[4]);
}

int			ft_print_hexa(va_list ap, t_directive *dir,
const char *str, char *base)
{
	unsigned int	nbr;
	int				t[5];

	t[0] = ft_handle_flags(dir, str);
	if ((t[1] = ft_handle_width(ap, dir, str)) < 0)
	{
		t[1] = -t[1];
		t[0] = 1;
	}
	t[2] = ft_handle_precision(ap, dir, str);
	nbr = va_arg(ap, unsigned int);
	t[3] = 0;
	ft_putunbr_base(nbr, base, &t[3], -1);
	if (!nbr && dir->precision_start < dir->precision_end && !t[2] && !t[1])
		return (0);
	if (t[1] && !t[0])
		ft_print_spaces(t[2] > t[3] ? t[1] - t[2] : t[1] - t[3]);
	return (ft_handle_return(dir, nbr, base, t));
}
