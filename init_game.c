/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/05 10:15:11 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_variables(t_data *data)
{
	data->player = 0;
	data->images = 0;
	data->moves = 0;
	data->coins = 0;
	data->total_coins = 0;
	data->endgame = 0;
	data->refresh = 0;
	data->fps = 30;
	data->coin_anim = 1;
	data->mario_anim = 1;
	data->gamestart = 0;
	data->movement = 0;
	data->dir = 0;
	data->ammo = 0;
	data->exits = 0;
	data->enemies = 0;
	data->start = 0;
}

void	load_images(t_data *data)
{
	load_image("images/back.xpm", data);
	load_image("images/brick.xpm", data);
	load_image("images/coin.xpm", data);
	load_image("images/coin2.xpm", data);
	load_image("images/coin3.xpm", data);
	load_image("images/treasure.xpm", data);
	load_image("images/treasure2.xpm", data);
	load_image("images/mario1.xpm", data);
	load_image("images/mario2.xpm", data);
	load_image("images/mario3.xpm", data);
	load_image("images/mario4.xpm", data);
	load_image("images/mario5.xpm", data);
	load_image("images/mario6.xpm", data);
	load_image("images/mario7.xpm", data);
	load_image("images/mario8.xpm", data);
	load_image("images/cursor.xpm", data);
	load_image("images/mario_unchained.xpm", data);
	load_image("images/blue.xpm", data);
	load_image("images/clouds.xpm", data);
	load_image("images/enemy1.xpm", data);
	load_image("images/enemy2.xpm", data);
	load_image("images/enemy3.xpm", data);
	load_image("images/enemy4.xpm", data);
	load_image("images/enemy5.xpm", data);
	load_image("images/enemy6.xpm", data);
}
