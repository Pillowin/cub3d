/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:00:31 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 12:45:25 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	return 0 means no flag
**	return 1 means flag '-' is used
*/

static int	ft_handle_flags(t_directive *dir, const char *str)
{
	if (dir->flags_end - dir->flags_start)
	{
		if (ft_strlchr(&str[dir->flags_start], '-',
			dir->flags_end - dir->flags_start))
			return (1);
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

static int	ft_handle_return(t_directive *dir, char *s, int t[3])
{
	int ret;

	if (t[0] == 1)
	{
		if (dir->precision_start < dir->precision_end
				&& t[2] < (int)ft_strlen(s))
			ft_print_spaces(t[1] - t[2]);
		else
			ft_print_spaces(t[1] - (int)ft_strlen(s));
	}
	else if (t[0] == 2)
		ft_print_zeros(t[1] - (int)ft_strlen(s));
	if (t[1] > (int)ft_strlen(s)
	|| (dir->precision_start < dir->precision_end && t[1] > t[2] && t[2] >= 0))
		ret = t[1];
	else if (dir->precision_start < dir->precision_end
			&& t[2] <= (int)ft_strlen(s))
		ret = t[2];
	else
		ret = (int)ft_strlen(s);
	return (ret);
}

/*
**	t[0] is flags
**	t[1] is width
**	t[2] is precision
*/

int			ft_print_str(va_list ap, t_directive *dir, const char *str)
{
	char	*s;
	int		t[3];

	t[0] = ft_handle_flags(dir, str);
	t[1] = ft_handle_width(ap, dir, str);
	if (t[1] < 0)
	{
		t[1] = -t[1];
		t[0] = 1;
	}
	t[2] = ft_handle_precision(ap, dir, str);
	if (!(s = va_arg(ap, char *)))
		s = "(null)";
	if (!t[0] && t[1] && dir->precision_start < dir->precision_end)
		ft_print_spaces(t[1] -
			(t[2] < (int)ft_strlen(s) ? t[2] : (int)ft_strlen(s)));
	else if (!t[0] && t[1])
		ft_print_spaces(t[1] - (int)ft_strlen(s));
	if (dir->precision_start < dir->precision_end)
		ft_putlstr(s, t[2]);
	else
		ft_putstr(s);
	return (ft_handle_return(dir, s, t));
}
