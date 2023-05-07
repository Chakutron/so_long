/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:24:00 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:21:28 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}
*/
char	*ft_strdup2(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static char	*write_buffer(int fd, char *buffer)
{
	char	*str;
	int		readed;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	readed = 42;
	while (ft_strchr2(str, '\n') < 0 && readed > 0)
	{
		readed = read(fd, str, BUFFER_SIZE);
		str[readed] = '\0';
		if (readed > 0)
			buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

static char	*work_the_buffer(char *buffer)
{
	int		i;
	char	*str;
	int		x;

	i = ft_strchr2(buffer, '\n');
	if (i >= 0)
		x = 2;
	else
		x = 1;
	if (i == -1)
		return (ft_strdup2());
	if (i == -2)
		i = ft_strlen(buffer);
	str = malloc(sizeof(char) * (i + x));
	if (!str)
		return (NULL);
	ft_strlcpy2(str, buffer, i);
	ft_substr2(buffer, i + 1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = write_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	if (!ft_strlen(buffer))
		return (free(buffer), buffer = NULL, NULL);
	line = work_the_buffer(buffer);
	return (line);
}
