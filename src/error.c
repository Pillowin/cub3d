/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 20:20:46 by agautier          #+#    #+#             */
/*   Updated: 2020/12/19 20:20:47 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

const char *g_err[6] = {
	"problème de joueur.\n",
	"la map est ouverte.\n",
	"la résolution n'est pas complète.\n",
	"texture non conforme.\n",
	"il manque une couleur.\n",
	"les données d'affichages ne sont pas conformes.\n"
};

int		set_error(t_game *game, enum e_err error)
{
	game->err = error;
	return (0);
}

void	ft_error(t_game *game)
{
	//TODO: free tout ce qui est friablent
	ft_putstr_fd("\033[31mErreur: \033[0m", STDERR_FILENO);
	(void)game;
	ft_putstr_fd((char *)g_err[game->err], STDERR_FILENO);
	exit(1);
}
