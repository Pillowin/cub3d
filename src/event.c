/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:07:40 by agautier          #+#    #+#             */
/*   Updated: 2020/12/03 16:52:44 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	global_event(t_game *game)
{
	mlx_hook(game->mlx.win, CLIENT_MESSAGE, STRUCTURE_NOTIFY_MASK,
			close_win, game);
	mlx_hook(game->mlx.win, VISIBILITY_NOTIFY, VISIBILITY_CHANGE_MASK,
			minimise_hook, game);
	mlx_hook(game->mlx.win, KEY_PRESS, KEY_PRESS_MASK, event_hook, game);
}

int		minimise_hook(t_game *game)
{
	mlx_put_image_to_window(game->mlx.id, game->mlx.win, game->mlx.img.id, 0, 0);
	return (0);
}

int		event_hook(int keycode, t_game *game)
{
	int			i;
	const int	tab[6] = {W_KEY, S_KEY, A_KEY, D_KEY, ESC_KEY, 0};
	int			(*const tab_f[5])(t_game *) = {
			forward, backward, left, right, close_win};

	i = 0;
	while (tab[i])
	{
		if (keycode == tab[i])
		{
			tab_f[i](game);
			break ;
		}
		i++;
	}
	return (0);
}
