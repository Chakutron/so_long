/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:13:22 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_mouse_click(int button, int x, int y, t_data *data)
{
	int	i;

	if (button == 1 && data->ammo > 0)
	{
		data->ammo -= 1;
		if (data->enemies > 0)
		{
			i = 0;
			while (i < data->enemies)
			{
				if (data->enemy[i].alive)
				{
					if ((data->enemy[i].x == x / 50)
						&& (data->enemy[i].y == y / 50 - 1))
					{
						data->enemy[i].alive = 0;
					}
				}
				i++;
			}
		}
	}
	else if (button == 3)
		data->ammo = data->enemies;
	return (0);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	static int	old_x = 0;
	static int	old_y = 0;
	int			tmp_x;
	int			tmp_y;

	data->cursor_x = x;
	data->cursor_y = y;
	tmp_x = x / 50;
	tmp_y = y / 50 - 1;
	if (tmp_x != old_x || tmp_y != old_y)
	{
		old_x = tmp_x;
		old_y = tmp_y;
	}
	return (0);
}

void	check_movement_keys(int keysym, t_data *data, int x, int y)
{
	if (keysym == 119 || keysym == 65362)
	{
		if (y - 1 >= 0 && data->map[x][y - 1] != '1')
			update_player(data, data->player_x, data->player_y - 1);
	}
	else if (keysym == 115 || keysym == 65364)
	{
		if (y + 1 < data->map_y && data->map[x][y + 1] != '1')
			update_player(data, data->player_x, data->player_y + 1);
	}
	else if (keysym == 97 || keysym == 65361)
	{
		if (x - 1 >= 0 && data->map[x - 1][y] != '1')
			update_player(data, data->player_x - 1, data->player_y);
		data->dir = 1;
	}
	else if (keysym == 100 || keysym == 65363)
	{
		if (x + 1 < data->map_x && data->map[x + 1][y] != '1')
			update_player(data, data->player_x + 1, data->player_y);
		data->dir = 0;
	}
}

void	check_extra_keys(int keysym, t_data *data)
{
	int	i;

	if (keysym == 65451)
	{
		data->fps += 1;
		ft_printf("- FPS: %i\n", data->fps);
	}
	else if (keysym == 65453)
	{
		data->fps -= 1;
		if (data->fps < 1)
			data->fps = 1;
		ft_printf("- FPS: %i\n", data->fps);
	}
	else if (keysym == 32)
	{
		i = 0;
		while (i < data->enemies)
		{
			ft_printf("enemy[%i] alive=%i x=%i y=%i anim=%i\n", i,
				data->enemy[i].alive, data->enemy[i].x, data->enemy[i].y,
				data->enemy[i].anim);
			i++;
		}
	}
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_game(data);
	check_movement_keys(keysym, data, data->player_x, data->player_y);
	check_extra_keys(keysym, data);
	return (0);
}
