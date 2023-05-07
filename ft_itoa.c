/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:55:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/18 12:33:42 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_size(long int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static void	worker(char *str, int size, long int num)
{
	int	neg;

	neg = 0;
	str[size] = '\0';
	if (num < 0)
	{
		num *= -1;
		neg = 1;
		size--;
	}
	while (size)
	{
		str[size + neg - 1] = 48 + (num % 10);
		num /= 10;
		size--;
	}
	if (neg)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	long int	num;
	int			size;
	char		*str;

	num = n;
	size = check_size(num);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	worker(str, size, num);
	return (str);
}
