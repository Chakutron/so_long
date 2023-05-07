/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/30 19:03:40 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_move_n(t_data *data, int x, int y, int i)
{
	if ((data->map[x][y - 1] == '0') || (data->map[x][y - 1] == 'P'))
	{
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'M';
		data->enemy[i].y -= 1;
	}
}

void	enemy_move_s(t_data *data, int x, int y, int i)
{
	if ((data->map[x][y + 1] == '0') || (data->map[x][y + 1] == 'P'))
	{
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'M';
		data->enemy[i].y += 1;
	}
}

void	enemy_move_w(t_data *data, int x, int y, int i)
{
	if ((data->map[x - 1][y] == '0') || (data->map[x - 1][y] == 'P'))
	{
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'M';
		data->enemy[i].x -= 1;
	}
}

void	enemy_move_e(t_data *data, int x, int y, int i)
{
	if ((data->map[x + 1][y] == '0') || (data->map[x + 1][y] == 'P'))
	{
		data->map[x][y] = '0';
		data->map[x + 1][y] = 'M';
		data->enemy[i].x += 1;
	}
}

void	enemy_move(t_data *data)
{
	int	i;
	int	num;

	if (data->enemies > 0)
	{
		i = 0;
		while (i < data->enemies)
		{
			if (data->enemy[i].alive)
			{
				srand(clock());
				num = rand() % 4 + 1;
				if (num == 1)
					enemy_move_n(data, data->enemy[i].x, data->enemy[i].y, i);
				else if (num == 2)
					enemy_move_s(data, data->enemy[i].x, data->enemy[i].y, i);
				else if (num == 3)
					enemy_move_w(data, data->enemy[i].x, data->enemy[i].y, i);
				else if (num == 4)
					enemy_move_e(data, data->enemy[i].x, data->enemy[i].y, i);
			}
			i++;
		}
	}
}
