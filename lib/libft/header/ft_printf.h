/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:03:10 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 12:09:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct	s_directive
{
	int flags_start;
	int flags_end;
	int	width_start;
	int	width_end;
	int precision_start;
	int precision_end;
	int type_start;
	int type_end;
	int pos;
}				t_directive;

void			ft_print_zeros(int n);
void			ft_print_spaces(int n);

int				ft_print_char(va_list ap, t_directive *dir, const char *str);
int				ft_print_str(va_list ap, t_directive *dir, const char *str);
int				ft_print_ptr(va_list ap, t_directive *dir, const char *str);
int				ft_print_int(va_list ap, t_directive *dir, const char *str);
int				ft_print_uint(va_list ap, t_directive *dir, const char *str);
int				ft_print_hexa(va_list ap, t_directive *dir, const char *str,
char *base);
int				ft_print_percent(va_list ap, t_directive *dir, const char *str);

int				ft_parse_ptf(t_directive *dir, const char *str);
int				ft_dispatch_ptf(t_directive *dir, va_list ap, const char *str);

int				ft_printf(const char *format, ...);

#endif
