/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:21:13 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/11 19:23:22 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	count;
	size_t	offset;

	count = 0;
	offset = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (s1[count] != '\0' && count < n)
	{
		offset = 0;
		while (s1[count + offset] == s2[offset]
			&& s2[offset] != '\0' && count + offset < n)
			offset++;
		if (offset == ft_strlen(s2))
			return ((char *)(s1 + count));
		count++;
	}
	return (NULL);
}
