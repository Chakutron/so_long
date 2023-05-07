/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/05 10:53:29 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_data *data)
{
	data->endgame = 1;
	ft_printf("--- GAME CLOSED ---\n");
	return (0);
}

void	start_game(t_data *data)
{
	mlx_loop(data->mlx_ptr);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_x * 50,
			data->map_y * 50 + 100, "SO_LONG by Chaku");
	if (!data->win_ptr)
		free(data->win_ptr);
	else
	{
		mlx_loop_hook(data->mlx_ptr, &render, data);
		mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
		mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask,
			&handle_mouse_move, data);
		mlx_hook(data->win_ptr, 17, 1L << 0, &close_game, data);
		mlx_mouse_hook(data->win_ptr, handle_mouse_click, data);
		mlx_mouse_hide(data->mlx_ptr, data->win_ptr);
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, data->map_x / 2 * 50,
			data->map_y / 2 * 50 + 50);
		mlx_do_key_autorepeatoff(data->mlx_ptr);
		mlx_set_font(data->mlx_ptr, data->win_ptr,
			"-sony-*-*-*-*-*-24-*-*-*-*-*-*");
		ft_printf("--- GAME STARTED ---\n");
		mlx_loop(data->mlx_ptr);
	}
}

void	open_map(t_data *data)
{
	ft_printf("- Loading map..\n\n");
	load_map(data);
	if (data->player != 1 || data->exits != 1 || data->total_coins == 0)
		print_error(data, 0);
	if (check_map(data) == -1)
		ft_printf("\033[0;31m* ERROR found in map: %s\n\n", data->file);
	else
	{
		ft_printf("- Map loaded! (%ix%i)\n\n", data->map_x, data->map_y);
		load_images(data);
		data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
				WINDOW_HEIGHT, "SO_LONG [Intro] by Chaku");
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image[16].ptr, WINDOW_WIDTH / 2 - data->image[16].w / 2,
			WINDOW_HEIGHT / 2 - data->image[16].h / 2);
		mlx_loop_hook(data->mlx_ptr, &title_render, data);
		mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &title_keypress, data);
		ft_printf("\nPress the SPACE key to continue..\n\n");
		start_game(data);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	init_variables(&data);
	ft_printf("\n\n\033[0;32m*** SO_LONG by Chaku ***\033[0m\n\n");
	if (argc == 2)
	{
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (MLX_ERROR);
		data.file = argv[1];
		if (check_extension(&data))
			print_error(&data, 3);
		open_map(&data);
		mlx_do_key_autorepeaton(data.mlx_ptr);
		unload_images(&data);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
}
