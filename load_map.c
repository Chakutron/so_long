/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/05 10:53:34 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(t_data *data)
{
	int	i;

	i = ft_strlen(data->file) - 4;
	if (data->file[i] == '.' && data->file[i + 1] == 'b'
		&& data->file[i + 2] == 'e' && data->file[i + 3] == 'r')
		return (0);
	return (1);
}

void	load_new_enemy(t_data *data, int x, int y)
{
	data->enemy[data->enemies].anim = 1;
	data->enemy[data->enemies].x = x;
	data->enemy[data->enemies].y = y;
	data->enemy[data->enemies].alive = 1;
	data->enemies += 1;
	data->ammo += 1;
}

void	print_error(t_data *data, int error)
{
	ft_printf("\n\n\033[0;31m* ERROR found in map: %s\n", data->file);
	if (error == 1 || error == 2)
		ft_printf(" - Wrong format!\n");
	else if (error == 3)
		ft_printf(" - Wrong extension file!\n");
	else
	{
		if (data->player != 1)
			ft_printf(" - Invalid PLAYER count!\n");
		if (data->exits != 1)
			ft_printf(" - Invalid EXIT count!\n");
		if (data->total_coins == 0)
			ft_printf(" - Invalid COINS count!\n");
	}
	exit (0);
}

void	read_map(t_data *data, char *line, int x, int y)
{
	if (line[0] == '\0' || line[0] == '\n')
		print_error(data, 2);
	data->map[x][y] = line[x];
	ft_printf("%c", line[x]);
	if (line[x] == 'P')
	{
		data->player_x = x;
		data->player_y = y;
		data->player++;
	}
	else if (line[x] == 'C')
		data->total_coins += 1;
	else if (line[x] == 'M')
		load_new_enemy(data, x, y);
	else if (line[x] == 'E')
		data->exits += 1;
	else if (line[x] != '1' && line[x] != '0' && line[x] != '\n')
		print_error(data, 1);
}

void	load_map(t_data *data)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	fd = open(data->file, O_RDONLY);
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		x = 0;
		while (line[x])
		{
			read_map(data, line, x, y);
			x++;
		}
		y++;
		free(line);
	}
	data->map_x = x - 1;
	data->map_y = y;
	close(fd);
}
