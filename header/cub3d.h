/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:51:00 by agautier          #+#    #+#             */
/*   Updated: 2021/01/29 16:47:32 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>

# define CLIENT_MESSAGE			33
# define STRUCTURE_NOTIFY_MASK	131072L
# define VISIBILITY_NOTIFY		15
# define VISIBILITY_CHANGE_MASK	65536L
# define KEY_PRESS_MASK			0
# define KEY_RELEASE_MASK		1
# define KEY_PRESS				2
# define KEY_RELEASE			3

# define DEG			0.0174533
# define RAD			57
# define FOV			60
# define PLAYER_SIZE	3

# define ESC_KEY			65307
# define Z_KEY				119
# define Q_KEY				97
# define S_KEY				115
# define D_KEY				100
# define ARROW_LEFT_KEY		65361
# define ARROW_RIGHT_KEY	65363

# define TITLE		"Cub3D"
# define TITLE_BMP	"Cub3D.bmp"

# define BMP_FILE_HEADER_SIZE 14
# define BMP_INFO_HEADER_SIZE 40

enum	e_err {
	ERR_MAP,
	ERR_DATA,
	ERR_TEXTURE,
	ERR_MALLOC,
	ERR_ARG,
	ERR_BMP,
	ERR_BMP_HEADER,
	ERR_BMP_IMG
};

typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct	s_dpos
{
	double	x;
	double	y;
}				t_dpos;

typedef struct	s_img
{
	void	*id;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
	t_pos	res;
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

typedef struct	s_key
{
	int		z;
	int		q;
	int		s;
	int		d;
	int		arrow_left;
	int		arrow_right;
}				t_key;

typedef struct	s_player
{
	t_pos	pos;
	t_pos	delta;
	double	angle;
	int		size;
	t_key	key;
	t_color	color;
}				t_player;

typedef struct	s_ray
{
	double	x;
	double	y;
	double	a;
}				t_ray;

typedef struct	s_sprite
{
	t_pos	pos;
	double	dist;
	int		visible;
}				t_sprite;

typedef struct	s_calc_sprite
{
	int				sprite_curr;
	double			side;
	int				y_begin;
	int				y_curr;
	int				x_begin;
	int				x_curr;
	double			col_width;
	t_color			col;
	unsigned int	color;
}				t_calc_sprite;

typedef struct	s_dda
{
	int		nb_ray;
	int		limit;
	double	dist_h;
	double	dist_v;
	t_pos	map_pos;
	t_pos	max;
	t_ray	ray;
	t_dpos	offset;
	t_dpos	inter_h;
	t_dpos	inter_v;
	t_color	col;
	t_dpos	line;
	double	cos_angle;
	double	dist_t;
}				t_dda;

typedef struct	s_game
{
	t_mlx		mlx;
	char		**map;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	t_img		north_data;
	t_img		south_data;
	t_img		west_data;
	t_img		east_data;
	t_img		sprite_data;
	t_res		res;
	t_color		floor;
	t_color		ceiling;
	t_player	player;
	t_dda		dda;
	double		*dists;
	t_sprite	*sprites;
	int			nb_sprite;
	enum e_err	err;
	int			speed;
	int			rota_speed;
}				t_game;

/*
** Cardinal check
*/
void			find_max(t_game *game, int *max_x, int *max_y);
int				check_horizontaly_begin(t_game *game);
int				check_horizontaly_end(t_game *game);
int				check_verticaly_begin(t_game *game);
int				check_verticaly_end(t_game *game);

/*
** Check map
*/
int				check_player(t_game *game);
int				find_zeros(t_game *game);
int				check_closed_map(t_game *game);

/*
** Parse utils
*/

int				parsed_data(int *parsing);
int				find_elem(char **words, const char **tab);
int				line_is_spaces(char *str);
int				is_player(t_game *game, int x, int y);
char			*fill_buffer(char *line);

/*
** Parse
*/

void			global_parse(char *filename, t_game *game);
void			parse_data(char *line, t_game *game, int *data_parsed);
int				parse_map(t_game *game, char *buffer);

/*
** BMP
*/

int				ft_create_bmp(t_game *game);

/*
** Draw
*/

void			draw_columns(t_game *game);

/*
** Engine
*/

void			dda_horizontal(t_game *game, t_dda *dda);
void			dda_vertical(t_game *game, t_dda *dda);
void			find_intersection(t_game *game);

/*
** Error
*/

int				set_error(t_game *game, enum e_err error);
void			ft_error(t_game *game);

/*
** Event
*/

int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				event_hook(int keycode, t_game *game);
void			global_event(t_game *game);
int				minimise_hook(t_game *game);

/*
** Fill_data
*/

int				fill_color(t_game *game, char **words, int index);
void			check_color(t_game *game, char **words);
int				fill_texture(t_game *game, char **words, int index);
int				fill_resolution(t_game *game, char **words, int index);

/*
** Free
*/

void			free_split(char **words);
void			free_game(t_game *game);

/*
** Image
*/

t_img			init_img(t_game *game);
void			global_img(t_game *game, int argc);

/*
** Move player
*/

void			fix_speed(t_game *game);
int				forward(t_game *game);
int				backward(t_game *game);
int				left(t_game *game);
int				right(t_game *game);
/*
** Player
*/
void			move_player(t_game *game);
void			init_player(t_game *game);

/*
** Put texture
*/

void			put_pixel(t_game *game, int x, int y, t_color c);

/*
** Raycast
*/

void			raycast(t_game *game);
void			raycaster(t_game *game);

/*
** Rotate player
*/

int				rotate_left(t_game *game);
int				rotate_right(t_game *game);

/*
** Sprite_draw
*/

void			draw_sprite(t_game *game);

/*
** Sprite
*/

void			find_sprites(t_game *game);
void			calc_dist_sprite(t_game *game);
void			fill_visibility(t_game *game);

/*
** Textures
*/

void			init_textures(t_game *game, t_img *tex_data, char *tex_name);

/*
** Utils
*/

int				check_tex_type(char *words);
double			dist(t_game *game, t_dpos inter);
int				ft_abs(int x);
void			init_dda(t_game *game);
int				check_cub(t_game *game, const char *file);

/*
** Window
*/

void			global_win(t_game *game);
int				close_win(t_game *game);

#endif
