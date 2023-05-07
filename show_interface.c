/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:03:27 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_text(t_data *data)
{
	char	*text;
	int		color;

	color = 0x000000;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 40, color, "Movements:");
	text = ft_itoa(data->moves);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 140, 40, color, text);
	free(text);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10,
		data->map_y * 50 + 90, color, "Coins:");
	text = ft_itoa(data->coins);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 90,
		data->map_y * 50 + 90, color, text);
	free(text);
	if (data->enemies > 0)
	{
		mlx_string_put(data->mlx_ptr, data->win_ptr, data->map_x * 41 - 20, 40,
			color, "Ammo:");
		text = ft_itoa(data->ammo);
		mlx_string_put(data->mlx_ptr, data->win_ptr, data->map_x * 41 + 50, 40,
			color, text);
		free(text);
	}
}

void	show_interface(t_data *data)
{
	int			x;
	static int	cloud_x = WINDOW_WIDTH / 2 - 200;

	x = 0;
	while (x < data->map_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image[17].ptr, x * 50, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image[17].ptr, x * 50, data->map_y * 50 + 50);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->image[18].ptr, cloud_x, 0);
	cloud_x++;
	if (cloud_x > data->map_x * 50 - 50)
		cloud_x = -200;
	show_text(data);
}
