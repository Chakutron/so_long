/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   titles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/30 19:53:23 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	title_render(t_data *data)
{
	if (data->gamestart == 1)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	title_keypress(int keysym, t_data *data)
{
	(void)data;
	if (keysym == 32)
		data->gamestart += 1;
	return (0);
}
