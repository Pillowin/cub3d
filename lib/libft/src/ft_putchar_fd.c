/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:46:43 by agautier          #+#    #+#             */
/*   Updated: 2020/11/11 14:04:26 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Écrit le caractère ’c’ sur le file descriptor donné.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
