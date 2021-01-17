
// void		draw_map(t_game *game)
// {
// 	int			x;
// 	int			y;
// 	t_pos		size;

// 	size.x = 10;
// 	size.y = 10;
// 	y = 0;
// 	while (y < size.y)
// 	{
// 		x = 0;
// 		while (x < size.x)
// 		{
// 			if (game->map[y][x] == '1')
// 				put_square(game, (t_pos){x * (size.x * size.y), y * (size.x *
// 					size.y)}, (size.x * size.y) - 1, (t_color){255, 255, 255});
// 			else
// 				put_square(game, (t_pos){x * (size.x * size.y), y * (size.x *
// 					size.y)}, (size.x * size.y) - 1, (t_color){0, 0, 0});
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void		draw_player(t_game *game)
// {
// 	t_pos direction;
// 	t_pos pos;

// 	pos.x = game->player.pos.x + game->player.size / 2;
// 	pos.y = game->player.pos.y + game->player.size / 2;
// 	direction.x = pos.x + cos(game->player.angle) * 25;
// 	direction.y = pos.y + sin(game->player.angle) * 25;
// 	draw_line(game, pos, direction, game->player.color);
// 	put_square(game, game->player.pos, game->player.size, game->player.color);
// }

// void	player(t_game *game, t_pos pos, int size, t_color c)
// {
// 	game->player.pos.x = pos.x;
// 	game->player.pos.y = pos.y;
// 	game->player.size = size;
// 	game->player.color = c;
// }

// int		event_hook(int keycode, t_game *game)
// {
	// int			i;
	// const int	tab[6] = {Z_KEY, S_KEY, Q_KEY, D_KEY, ESC_KEY, 0};
	// int			(*const tab_f[5])(t_game *) = {forward, backward, left, right,
	// 	close_win};

	// i = 0;
	// while (tab[i])
	// {
	// 	if (keycode == tab[i])
	// 	{
	// 		tab_f[i](game);
	// 		break ;
	// 	}
	// 	i++;
	// }
	// return (0);
// }


// static void	draw_line_loop(t_game *game, t_draw_line dl)
// {
// 	while (dl.a.x != dl.b.x || dl.a.y != dl.b.y)
// 	{
// 		put_pixel(game, dl.a.x, dl.a.y, dl.c);
// 		dl.e2 = dl.err;
// 		if (dl.e2 > -dl.d.x)
// 		{
// 			dl.err -= dl.d.y;
// 			dl.a.x += dl.s.x;
// 		}
// 		if (dl.e2 < dl.d.y)
// 		{
// 			dl.err += dl.d.x;
// 			dl.a.y += dl.s.y;
// 		}
// 	}
// }

// void		draw_line(t_game *game, t_pos a, t_pos b, t_color c)
// {
// 	t_draw_line	dl;

// 	dl.a = a;
// 	dl.b = b;
// 	dl.c = c;
// 	dl.d.x = ft_abs(dl.b.x - dl.a.x);
// 	if (dl.a.x < dl.b.x)
// 		dl.s.x = 1;
// 	else
// 		dl.s.x = -1;
// 	dl.d.y = ft_abs(dl.b.y - dl.a.y);
// 	if (dl.a.y < dl.b.y)
// 		dl.s.y = 1;
// 	else
// 		dl.s.y = -1;
// 	if (dl.d.x > dl.d.y)
// 		dl.err = dl.d.x / 2;
// 	else
// 		dl.err = -dl.d.y / 2;
// 	draw_line_loop(game, dl);
// }

// draw_line(
			// 	game,
			// 	(t_pos){dda->nb_ray * offset + i, dda->line.x},
			// 	(t_pos){dda->nb_ray * offset + i, dda->line.x + dda->line.y},
			// 	dda->col
			// );


// static void	put_color(t_game *game, int x, int y, t_color c)
// {
// 	game->mlx.img.data_addr[x + y + 0] = c.b;
// 	game->mlx.img.data_addr[x + y + 1] = c.g;
// 	game->mlx.img.data_addr[x + y + 2] = c.r;
// 	game->mlx.img.data_addr[x + y + 3] = (char)0;
// }

// void		draw_bg(t_game *game, t_color c, t_color f)
// {
// 	int x;
// 	int y;

// 	y = 0;
// 	while (y < game->mlx.img.size_line * game->res.y)
// 	{
// 		x = 0;
// 		while (x < game->mlx.img.size_line)
// 		{
// 			if (y < game->mlx.img.size_line * game->res.y / 2)
// 				put_color(game, x, y, c);
// 			else
// 				put_color(game, x, y, f);
// 			x += 4;
// 		}
// 		y += game->res.x;
// 	}
// }


// void	get_texture(t_map *map)
// {
// 	int	x;
// 	int	y;

// 	map->mlx.img.id = mlx_xpm_file_to_image(map->mlx.id, map->north, &map->res.x, &map->res.y);
// 	y = 0;
// 	while (y < 10)
// 	{
// 		x = 0;
// 		while (x < 10)
// 		{
// 			mlx_put_image_to_window(map->mlx.id, map->mlx.win, map->mlx.img.id,
// 			x * 64, y * 64);
// 			x += 1;
// 		}
// 		y += 1;
// 	}
// }


// void	draw_columns(t_game *game, t_dda *dda)
// {
// 	int	i;
// 	int	offset;
// 	int	y;

// 	offset = game->res.x / FOV + 1;
// 	i = 0;
// 	while (i < offset)
// 	{
// 		if (dda->nb_ray * offset + i <= game->res.x)
// 		{
// 			y = 0;
// 			while (y < dda->line.x - 1)
// 			{
// 				put_pixel(game, dda->nb_ray * offset + i, y, game->ceiling);
// 				put_pixel(game, dda->nb_ray * offset + i, y + dda->line.x + dda->line.y, game->floor);
// 				y++;
// 			}
// 			while (y < dda->line.x + dda->line.y)
// 			{
// 				put_pixel(game, dda->nb_ray * offset + i, y, dda->col);
// 				y++;
// 			}
// 		}
// 		i++;
// 	}
// }


// void	raycaster(t_game *game)
// {
// 	t_dda	dda;

// 	find_max(game, &(dda.max.x), &(dda.max.y));
// 	dda.ray.a = game->player.angle - FOV / 2 * DEG;
// 	dda.nb_ray = 0;
// 	while (dda.nb_ray < FOV)
// 	{
// 		raycast(game, &dda);
// 		draw_columns(game, &dda);
// 		dda.ray.a += DEG;
// 		dda.nb_ray++;
// 	}
// }
