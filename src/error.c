/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:56:53 by mamaquig          #+#    #+#             */
/*   Updated: 2020/12/22 22:04:555 by mamaquig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const char *g_err[4] = {
	"La description de map ne respecte pas les règles de carte.\n",
	"Les données d'affichages ne sont pas conformes.\n",
	"Les textures ne sont pas conformes.\n",
	"Une allocation de mémoire à échoué.\n"
};

int		set_error(t_game *game, enum e_err error)
{
	game->err = error;
	return (0);
}

void	ft_error(t_game *game)
{
	free_game(game);
	ft_putstr_fd("\033[31mError\033[0m\n", STDERR_FILENO);
	ft_putstr_fd((char *)g_err[game->err], STDERR_FILENO);
	exit(1);
}
