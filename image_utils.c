/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:41:11 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/28 20:03:39 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	new_img(int w, int h, t_data *window)
{
	t_image	image;

	image.ptr = mlx_new_image(window->mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

t_image	new_file_img(char *path, t_data *window)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(window->mlx_ptr, path, &img.w, &img.h);
	img.addr = mlx_get_data_addr(img.ptr, &(img.bpp),
			&(img.line_len), &(img.endian));
	return (img);
}

void	put_pixel_img(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr;
	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img->w && y < img->h)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_image *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_len)
			+ (x * img->bpp / 8))));
}

void	put_img_to_img(t_image *dst, t_image *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->w)
	{
		j = 0;
		while (j < src->h)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
