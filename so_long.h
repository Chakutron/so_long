/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:44:15 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/05 10:48:46 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WINDOW_WIDTH 1800
# define WINDOW_HEIGHT 1350

# define MLX_ERROR 1

# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		endian;
	int		line_len;
}			t_image;

typedef struct s_enemy
{
	int		anim;
	int		x;
	int		y;
	int		alive;
}			t_enemy;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	*file;
	int		map_x;
	int		map_y;
	int		player;
	int		player_x;
	int		player_y;
	int		cursor_x;
	int		cursor_y;
	int		enemies;
	int		images;
	int		moves;
	int		coins;
	int		total_coins;
	int		endgame;
	int		start;
	int		refresh;
	int		fps;
	int		coin_anim;
	int		mario_anim;
	int		gamestart;
	int		movement;
	int		dir;
	int		ammo;
	int		exits;
	int		map[100][100];
	int		map2[100][100];
	t_image	image[100];
	t_enemy	enemy[500];
}			t_data;

t_image	new_img(int w, int h, t_data *window);
t_image	new_file_img(char *path, t_data *window);
void	put_pixel_img(t_image *img, int x, int y, int color);
void	put_img_to_img(t_image *dst, t_image *src, int x, int y);

void	init_variables(t_data *data);
int		check_extension(t_data *data);
void	print_error(t_data *data, int error);
void	load_map(t_data *data);
int		check_map(t_data *data);
void	load_image(char *file, t_data *data);
void	load_images(t_data *data);
int		title_render(t_data *data);
int		title_keypress(int keysym, t_data *data);
int		render(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_mouse_move(int x, int y, t_data *data);
int		handle_mouse_click(int button, int x, int y, t_data *data);
void	update_player(t_data *data, int x, int y);
void	work_animations(t_data *data);
void	show_map(t_data *data);
char	*ft_itoa(int n);
void	show_interface(t_data *data);
void	enemy_move(t_data *data);
int		close_game(t_data *data);
void	unload_images(t_data *data);

#endif
