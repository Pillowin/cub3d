/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:49:02 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 12:29:08 by agautier         ###   ########.fr       */
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

int			ft_print_percent(va_list ap, t_directive *dir, const char *str)
{
	int flags;
	int width;

	flags = ft_handle_flags(dir, str);
	width = ft_handle_width(ap, dir, str);
	if (width < 0)
	{
		width = -width;
		flags = 1;
	}
	if (!flags && width)
		ft_print_spaces(width - 1);
	else if (flags == 2 && width)
		ft_print_zeros(width - 1);
	ft_putchar_fd('%', STDOUT_FILENO);
	if (flags == 1)
		ft_print_spaces(width - 1);
	return (width ? width : 1);
}
