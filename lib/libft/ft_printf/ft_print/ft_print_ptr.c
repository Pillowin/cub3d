/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:47:30 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 12:40:19 by agautier         ###   ########.fr       */
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

/*
**	t[0] is flags
**	t[1] is width
**	t[2] is printed
*/

int			ft_print_ptr(va_list ap, t_directive *dir, const char *str)
{
	int		t[3];
	void	*ptr;

	t[0] = ft_handle_flags(dir, str);
	if ((t[1] = ft_handle_width(ap, dir, str)) < 0)
	{
		t[1] = -t[1];
		t[0] = 1;
	}
	ptr = va_arg(ap, void*);
	t[2] = 2;
	if (dir->precision_end - dir->precision_start == 0)
		ft_putulnbr_base((unsigned long)ptr, "0123456789abcdef", &t[2], -1);
	if (!t[0] && t[1])
		ft_print_spaces(t[1] - t[2]);
	else if (t[0] == 2 && t[1])
		ft_print_zeros(t[1] - t[2]);
	ft_putstr_fd("0x", STDOUT_FILENO);
	t[2] = 2;
	if (dir->precision_end - dir->precision_start == 0)
		ft_putulnbr_base((unsigned long)ptr, "0123456789abcdef", &t[2], 1);
	if (t[0] == 1)
		ft_print_spaces(t[1] - t[2]);
	return (t[1] > t[2] ? t[1] : t[2]);
}
