/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:10:24 by agautier          #+#    #+#             */
/*   Updated: 2020/11/23 21:27:21 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# define ESC_KEY				65307
# define DESTROY_NOTIFY			17
# define STRUCTURE_NOTIFY_MASK	131072L
# define VISIBILITY_NOTIFY		15
# define VISIBILITY_CHANGE_MASK	65536L
# define KEY_PRESS				2
# define KEY_PRESS_MASK			1

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

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

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_player
{
	t_pos	pos;
	t_pos	delta;
	double	angle;
	int		size;
	t_color	color;
}				t_player;

// typedef struct	s_map
// {
// 	int	**map;
// }				t_map;

typedef struct	s_game
{
	t_mlx		mlx;
	int		**map;
	t_res		res;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
	t_color		bg_color;
}				t_game;

typedef struct	s_draw_line
{
	t_pos	a;
	t_pos	b;
	t_color	c;
	t_pos	d;
	t_pos	s;
	int		err;
	int		e2;
}				t_draw_line;

/*
**	Window
*/
void			global_win(t_game *game);
int				close_win(t_game *game);

/*
**	Event
*/
void			global_event(t_game *game);
int				event_hook(int keycode, t_game *game);
int				minimise_hook(t_game *game);

/*
**	Image
*/
t_img			init_img(t_game *game);
void			global_img(t_game *game);

/*
**	Parse
*/
void			global_parse(char *filename, t_game *game);
void			parse_line(char *line, t_game *game);

/*
**	Fill struct
*/
int				fill_resolution(t_game *game, char **words, int index);
int				fill_texture(t_game *game, char **words, int index);
int				fill_color(t_game *game, char **words, int index);

/*
**	Free
*/
void			free_textures(t_game *game);
void			free_split(char **words);

/*
**	Engine
*/
void			player(t_game *game, t_pos pos, int size, t_color c);
void			move_player(t_game *game, t_pos pos);
void			raycaster(t_game *game);

/*
**	Draw
*/
void			draw_map(t_game *game);
void			draw_bg(t_game *game, t_color c);
void			draw_player(t_game *game);
void			draw_line(t_game *game, t_pos a, t_pos b, t_color c);

/*
**	Key player
*/
int				forward(t_game *game);
int				backward(t_game *game);
int				left(t_game *game);
int				right(t_game *game);

/*
**	Put texture
*/
void			put_pixel(t_game *game, int x, int y, t_color c);
void			put_square(t_game *game, t_pos pos, int size, t_color c);

#endif
