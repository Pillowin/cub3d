/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:14:58 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 12:23:01 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch_ptf(t_directive *dir, va_list ap, const char *str)
{
	if (str[dir->type_start] == 'c')
		return (ft_print_char(ap, dir, str));
	else if (str[dir->type_start] == 's')
		return (ft_print_str(ap, dir, str));
	else if (str[dir->type_start] == 'p')
		return (ft_print_ptr(ap, dir, str));
	else if (str[dir->type_start] == 'd' || str[dir->type_start] == 'i')
		return (ft_print_int(ap, dir, str));
	else if (str[dir->type_start] == 'u')
		return (ft_print_uint(ap, dir, str));
	else if (str[dir->type_start] == 'x')
		return (ft_print_hexa(ap, dir, str, "0123456789abcdef"));
	else if (str[dir->type_start] == 'X')
		return (ft_print_hexa(ap, dir, str, "0123456789ABCDEF"));
	else if (str[dir->type_start] == '%')
		return (ft_print_percent(ap, dir, str));
	return (0);
}
