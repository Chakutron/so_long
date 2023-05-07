/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:17:12 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(t_data *data, int x, int y)
{
	if (data->map[x][y] == 'E')
	{
		if (data->coins == data->total_coins)
		{
			ft_printf("\n\033[0;32mYOU COLLECTED ALL %i", data->total_coins);
			ft_printf(" COINS IN %i MOVEMENTS.\033[0m\n\n", data->moves);
			close_game(data);
			return ;
		}
		else
			return ;
	}
	data->map[data->player_x][data->player_y] = '0';
	data->player_x = x;
	data->player_y = y;
	data->movement = 1;
	if (data->map[data->player_x][data->player_y] == 'C')
		data->coins += 1;
	if (!data->endgame)
	{
		data->map[data->player_x][data->player_y] = 'P';
		data->moves += 1;
	}
}
