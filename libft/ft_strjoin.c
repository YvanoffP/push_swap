/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:15:19 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/13 17:35:28 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index;
	size_t	count;
	size_t	len_s1;
	size_t	len_s2;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = malloc(sizeof(char) * ((len_s1 + len_s2) + 1));
	if (!result)
		return (NULL);
	index = -1;
	count = 0;
	while (++index < len_s1)
		result[index] = s1[index];
	while (count < len_s2)
	{
		result[index++] = s2[count];
		count++;
	}
	result[index] = '\0';
	return (result);
}
