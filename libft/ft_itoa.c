/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:14:41 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/15 01:45:59 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int *nbr, int *isneg)
{
	int	count;
	int	nbrcpy;

	count = 0;
	if (*nbr == 0)
		return (1);
	if (*nbr < 0)
	{
		*nbr *= -1;
		nbrcpy = *nbr;
		count++;
		*isneg = 1;
	}
	else
		nbrcpy = *nbr;
	while (nbrcpy >= 1)
	{
		nbrcpy /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		isneg;
	int		len;
	char	*nb;

	nb = 0;
	isneg = 0;
	len = ft_nbrlen(&n, &isneg);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (NULL);
	nb[len] = '\0';
	while (--len >= 1)
	{
		nb[len] = (n % 10) + '0';
		n /= 10;
	}
	if (isneg == 1)
		nb[0] = '-';
	else
		nb[0] = (n % 10) + '0';
	return (nb);
}
