/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:11:10 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/23 18:05:13 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;

	count = ft_strlen(s);
	if (count >= 0)
	{
		while (s[count] != (char)c && count > 0)
			count--;
		if (s[count] == (char)c)
			return ((char *)(s + count));
	}
	return (NULL);
}
