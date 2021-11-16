/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:24:09 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/11/16 18:40:45 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

static void	fatal_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int	ft_atoi(const char *str)
{
	long	res;
	long	neg;
	long	count;

	res = 0;
	neg = 1;
	count = 0;
	while (ft_iswspace(str[count]))
		count++;
	if (str[count] == '-')
	{
		neg = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		res = (res * 10) + (str[count] - '0');
		count++;
	}
	res *= neg;
	if (res > 2147483647 || res < -2147483648)
		fatal_error();
	return ((int)res);
}
