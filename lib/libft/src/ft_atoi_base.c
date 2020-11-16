/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:44:12 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 13:59:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_str_err(char *str, char *base, int index, int base_len)
{
	int i;
	int err;

	while (str[index])
	{
		i = 0;
		err = 1;
		while (base[i])
		{
			if (str[index] == base[i])
				err = 0;
			if (str[index] != base[i] && i == (base_len - 1) && err)
				return (1);
			i++;
		}
		index++;
	}
	return (0);
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

static int	ft_get_index(char *str, int *nb_minus)
{
	int i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			*nb_minus = *nb_minus + 1;
		i++;
	}
	return (i);
}

static int	ft_get_digit(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

/*
**	Fonction qui convertit le début de la chaîne pointée par str en entier de
**	type int.
*/

int			ft_atoi_base(char *str, char *base)
{
	int i;
	int nb_minus;
	int result;
	int base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	nb_minus = 0;
	i = ft_get_index(str, &nb_minus);
	if (ft_is_str_err(str, base, i, base_len) || ft_is_base_err(base, base_len))
		return (0);
	result = 0;
	while (str[i])
	{
		result = result * base_len + ft_get_digit(str[i], base);
		i++;
	}
	if (nb_minus % 2)
		result = -result;
	return (result);
}
