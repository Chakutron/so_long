/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/30 18:51:59 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_player(t_data *data, t_image *canvas, int x, int y)
{
	put_img_to_img(canvas, &(data->image[0]), x * 50, y * 50 + 50);
	if (data->dir == 0)
	{
		if (data->mario_anim == 1 || data->mario_anim == 3)
			put_img_to_img(canvas, &(data->image[7]), x * 50, y * 50 + 50);
		else if (data->mario_anim == 2)
			put_img_to_img(canvas, &(data->image[8]), x * 50, y * 50 + 50);
		else if (data->mario_anim == 4)
			put_img_to_img(canvas, &(data->image[9]), x * 50, y * 50 + 50);
	}
	else if (data->dir == 1)
	{
		if (data->mario_anim == 1 || data->mario_anim == 3)
			put_img_to_img(canvas, &(data->image[11]), x * 50, y * 50 + 50);
		else if (data->mario_anim == 2)
			put_img_to_img(canvas, &(data->image[12]), x * 50, y * 50 + 50);
		else if (data->mario_anim == 4)
			put_img_to_img(canvas, &(data->image[13]), x * 50, y * 50 + 50);
	}
}

void	show_enemies(t_data *data, t_image *canvas, int x, int y)
{
	int	i;

	i = 0;
	while (i < data->enemies)
	{
		x = data->enemy[i].x * 50;
		y = data->enemy[i].y * 50;
		if (data->enemy[i].anim < 7)
			put_img_to_img(canvas, &(data->image[0]), x, y + 50);
		if (data->enemy[i].anim == 1)
			put_img_to_img(canvas, &(data->image[19]), x, y + 50);
		else if (data->enemy[i].anim == 2)
			put_img_to_img(canvas, &(data->image[20]), x, y + 50);
		else if (data->enemy[i].anim == 3)
			put_img_to_img(canvas, &(data->image[21]), x, y + 50);
		else if (data->enemy[i].anim == 4)
			put_img_to_img(canvas, &(data->image[22]), x, y + 50);
		else if (data->enemy[i].anim == 5)
			put_img_to_img(canvas, &(data->image[23]), x, y + 50);
		else if (data->enemy[i].anim == 6)
			put_img_to_img(canvas, &(data->image[24]), x, y + 50);
		i++;
	}
}

void	show_elements(t_data *data, t_image *canvas, int x, int y)
{
	if (data->map[x][y] == '0')
		put_img_to_img(canvas, &(data->image[0]), x * 50, y * 50 + 50);
	else if (data->map[x][y] == '1')
		put_img_to_img(canvas, &(data->image[1]), x * 50, y * 50 + 50);
	else if (data->map[x][y] == 'C')
	{
		put_img_to_img(canvas, &(data->image[0]), x * 50, y * 50 + 50);
		if (data->coin_anim == 1)
			put_img_to_img(canvas, &(data->image[2]), x * 50, y * 50 + 50);
		else if (data->coin_anim == 2 || data->coin_anim == 4)
			put_img_to_img(canvas, &(data->image[3]), x * 50, y * 50 + 50);
		else if (data->coin_anim == 3)
			put_img_to_img(canvas, &(data->image[4]), x * 50, y * 50 + 50);
	}
	else if (data->map[x][y] == 'E')
	{
		put_img_to_img(canvas, &(data->image[0]), x * 50, y * 50 + 50);
		if (data->coins != data->total_coins)
			put_img_to_img(canvas, &(data->image[5]), x * 50, y * 50 + 50);
		else
			put_img_to_img(canvas, &(data->image[6]), x * 50, y * 50 + 50);
	}
	else if (data->map[x][y] == 'P')
		show_player(data, canvas, x, y);
}

void	show_map(t_data *data)
{
	int		x;
	int		y;
	t_image	canvas;

	canvas = new_img(data->map_x * 50, data->map_y * 50 + 100, data);
	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			show_elements(data, &canvas, x, y);
			if (data->enemies > 0)
				show_enemies(data, &canvas, x, y);
			x++;
		}
		y++;
	}
	put_img_to_img(&canvas, &(data->image[15]), data->cursor_x - 25,
		data->cursor_y - 25);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, canvas.ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, canvas.ptr);
	show_interface(data);
}
