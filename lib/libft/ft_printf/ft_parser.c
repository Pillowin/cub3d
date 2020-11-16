/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 14:38:31 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 12:23:01 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_directive	*ft_parse_flags(t_directive *dir, const char *str)
{
	int	i;

	dir->flags_start = dir->pos;
	i = dir->pos;
	while (str[i] && (str[i] == '0' || str[i] == '-'))
		i++;
	dir->flags_end = dir->flags_start + i - dir->pos;
	dir->pos = dir->flags_end;
	return (dir);
}

static t_directive	*ft_parse_width(t_directive *dir, const char *str)
{
	int	i;

	dir->width_start = dir->pos;
	i = dir->pos;
	if (str[i] && str[i] == '*')
		i++;
	else
		while (str[i] && ft_isdigit(str[i]))
			i++;
	dir->width_end = dir->width_start + i - dir->pos;
	dir->pos = dir->width_end;
	return (dir);
}

static t_directive	*ft_parse_precision(t_directive *dir, const char *str)
{
	int	i;

	dir->precision_start = dir->pos;
	i = dir->pos;
	if (str[i] && str[i] == '.')
	{
		i++;
		while (str[i] && (ft_isdigit(str[i]) || str[i] == '*'))
			i++;
	}
	dir->precision_end = dir->precision_start + i - dir->pos;
	dir->pos = dir->precision_end;
	return (dir);
}

static t_directive	*ft_parse_type(t_directive *dir, const char *str)
{
	dir->type_start = dir->pos;
	if (str[dir->pos] && (
			str[dir->pos] == 'c' || str[dir->pos] == 's' ||
			str[dir->pos] == 'p' || str[dir->pos] == 'd' ||
			str[dir->pos] == 'i' || str[dir->pos] == 'u' ||
			str[dir->pos] == 'x' || str[dir->pos] == 'X' ||
			str[dir->pos] == '%'))
		dir->type_end = dir->type_start + 1;
	else
		dir->type_end = dir->type_start + 0;
	dir->pos = dir->type_end;
	return (dir);
}

int					ft_parse_ptf(t_directive *dir, const char *str)
{
	ft_parse_flags(dir, str);
	ft_parse_width(dir, str);
	ft_parse_precision(dir, str);
	ft_parse_type(dir, str);
	return (1);
}
