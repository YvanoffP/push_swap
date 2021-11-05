/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:58:45 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/15 02:45:50 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	src_len;

	index = 0;
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	while (src[index] != '\0' && index < (size - 1))
	{
		dst[index] = src[index];
		index++;
	}
	if (size < src_len)
		dst[size - 1] = '\0';
	else if (size != 0)
		dst[index] = '\0';
	return (src_len);
}
