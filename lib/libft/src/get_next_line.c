/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:22:53 by agautier          #+#    #+#             */
/*   Updated: 2020/12/19 20:22:54 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	tofree(char ***str)
{
	free(**str);
	**str = NULL;
}

int		get_next_part(char ***line, char **str, char **tmp, int nb)
{
	char *test;

	if (!(test = ft_strchr(*str, '\n')))
	{
		test = ft_strchr(*str, '\0');
		nb = 0;
	}
	else
		nb = 1;
	if (!(**line = ft_substr(*str, 0, ft_strlen(*str) - ft_strlen(test))))
	{
		free(*str);
		*str = NULL;
		return (-1);
	}
	if (nb == 1)
	{
		*tmp = *str;
		*str = ft_substr(test + 1, 0, ft_strlen(test + 1));
		free(*tmp);
	}
	else
		tofree(&str);
	return (nb);
}

int		get_next_line(int fd, char **line)
{
	char		*test;
	char		*tmp;
	static char *str = NULL;
	int			nb;

	tmp = NULL;
	if (!str)
		str = ft_strdup("");
	if (!tmp)
		tmp = calloc(sizeof(char), BUFFER_SIZE + 1);
	if (fd < 0 || !line || read(fd, tmp, 0) == -1)
		return (-1);
	while (!(ft_strchr(str, '\n')) && (nb = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[nb] = '\0';
		test = str;
		str = ft_strjoin(str, tmp);
		free(test);
	}
	free(tmp);
	tmp = NULL;
	nb = get_next_part(&line, &str, &tmp, nb);
	return (nb);
}
