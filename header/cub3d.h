/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:10:24 by agautier          #+#    #+#             */
/*   Updated: 2020/11/14 19:14:36 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define ESC_KEY				65307
# define DESTROY_NOTIFY			17
# define STRUCTURE_NOTIFY_MASK	131072L
# define VISIBILITY_NOTIFY		15
# define VISIBILITY_CHANGE_MASK	65536L

typedef struct	s_img
{
	void	*id;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_mlx
{
	void	*id;
	void	*win;
	t_img	img;
}				t_mlx;

typedef struct	s_res
{
	int	x;
	int	y;
}				t_res;

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct	s_map
{
	t_mlx	mlx;
	t_res	res;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	t_color	floor;
	t_color	ceiling;
}				t_map;

/*
**	Window
*/
void			global_win(t_map *map);
int				close_win(t_map *map);

/*
**	Event
*/
void			global_event(t_map *map);
int				event_hook(int keycode, t_map *map);
int				minimise_hook(t_map *map);

/*
**	Image
*/
void			global_img(t_map *map);
void			get_texture(t_map *map);

/*
**	Parse
*/
void			global_parse(char *filename, t_map *map);
void			parse_line(char *line, t_map *map);

/*
**	Fill struct
*/
int				fill_resolution(t_map *map, char **words, int index);
int				fill_texture(t_map *map, char **words, int index);
int				fill_color(t_map *map, char **words, int index);

/*
**	Free
*/
void			free_textures(t_map *map);
void			free_split(char **words);

/*
**	Engine
*/
void			raycast(t_map *map);

#endif
