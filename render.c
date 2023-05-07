/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:14:51 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_enemy_collision(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->enemies)
	{
		if ((data->enemy[i].x == data->player_x)
			&& (data->enemy[i].y == data->player_y) && data->enemy[i].alive)
		{
			ft_printf("\n\033[0;31mYOU LOSE MOTHERFUCKER!!\033[0;0m\n\n");
			close_game(data);
		}
		i++;
	}
}

void	check_movement(t_data *data)
{	
	if (data->refresh && data->gamestart > 0)
	{
		show_map(data);
		data->refresh = 0;
		data->start = clock();
		if (data->movement)
		{
			data->movement += 1;
			if (data->movement >= 3)
				data->movement = 0;
		}
	}
}

int	render(t_data *data)
{
	int			end;
	int			num;

	end = clock();
	if ((double)(end - data->start) / CLOCKS_PER_SEC > (1.0 / data->fps))
	{
		work_animations(data);
		srand(clock());
		num = rand() % data->fps;
		if (num <= (data->fps / 5))
			enemy_move(data);
		data->refresh = 1;
	}
	if (data->enemies > 0)
		check_enemy_collision(data);
	if (data->endgame)
	{
		mlx_mouse_show(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	else
		check_movement(data);
	return (0);
}
