/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:20:16 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 12:23:01 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_separator(char c)
{
	if ((unsigned char)c == '%')
		return (1);
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_directive	dir;
	int			i;
	int			ret;

	ret = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (ft_is_separator(format[i]))
		{
			dir.pos = i + 1;
			ft_parse_ptf(&dir, format);
			ret += ft_dispatch_ptf(&dir, ap, format);
			i = dir.pos;
		}
		else if (!ft_is_separator(format[i]))
		{
			ft_putchar_fd(format[i++], STDOUT_FILENO);
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}
