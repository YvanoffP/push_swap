/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:26:09 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/12 18:11:52 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	tot_len;
	size_t	original_len;

	count = 0;
	original_len = size;
	tot_len = ft_strlen(dst) + ft_strlen(src);
	while (dst[count] != '\0' && size > 0)
	{
		count++;
		size--;
	}
	if (size == 0)
		return (original_len + ft_strlen((char *)src));
	while (*src != '\0' && size > 1)
	{
		dst[count] = *src;
		src++;
		count++;
		size--;
	}
	dst[count] = '\0';
	return (tot_len);
}
