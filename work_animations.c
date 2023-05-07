/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:17:29 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_animations(t_data *data)
{
	if (data->coin_anim == 1)
		data->coin_anim = 2;
	else if (data->coin_anim == 2)
		data->coin_anim = 3;
	else if (data->coin_anim == 3)
		data->coin_anim = 4;
	else if (data->coin_anim == 4)
		data->coin_anim = 1;
}

void	player_animations(t_data *data)
{
	if (data->movement)
	{
		if (data->mario_anim == 2)
			data->mario_anim = 3;
		else if (data->mario_anim == 3)
			data->mario_anim = 4;
		else if (data->mario_anim == 4)
			data->mario_anim = 2;
		else
			data->mario_anim = 2;
	}
	else
		data->mario_anim = 1;
}

void	dead_enemy(t_data *data, int i)
{
	data->enemy[i].anim = 7;
	ft_printf("- Enemy[%i] is dead at %ix%i\n", i, data->enemy[i].x,
		data->enemy[i].y);
	data->map[data->enemy[i].x][data->enemy[i].y] = '0';
}

void	enemy_animations(t_data *data)
{
	int	i;

	if (data->enemies > 0)
	{
		i = 0;
		while (i < data->enemies)
		{
			if ((data->enemy[i].alive == 0) && (data->enemy[i].anim < 3))
				data->enemy[i].anim = 3;
			if (data->enemy[i].anim == 1)
				data->enemy[i].anim = 2;
			else if (data->enemy[i].anim == 2)
				data->enemy[i].anim = 1;
			else if (data->enemy[i].anim == 3)
				data->enemy[i].anim = 4;
			else if (data->enemy[i].anim == 4)
				data->enemy[i].anim = 5;
			else if (data->enemy[i].anim == 5)
				data->enemy[i].anim = 6;
			else if (data->enemy[i].anim == 6)
				dead_enemy(data, i);
			i++;
		}
	}
}

void	work_animations(t_data *data)
{
	coin_animations(data);
	player_animations(data);
	enemy_animations(data);
}
