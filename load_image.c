/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:14:02 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(char *file, t_data *data)
{
	data->image[data->images] = new_file_img(file, data);
	ft_printf("- Image[%i] loaded: (%s) (ptr=%p) (%ix%i pixels)\n", data->images,
		file, data->image[data->images].ptr, data->image[data->images].w,
		data->image[data->images].h);
	data->images += 1;
}

void	unload_images(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->images)
	{
		mlx_destroy_image(data->mlx_ptr, data->image[i].ptr);
		i++;
	}
}
