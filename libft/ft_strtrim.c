/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:05:02 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/15 02:48:36 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (0);
		set++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	finish;
	char	*ret;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	finish = ft_strlen(s1);
	count = 0;
	while (ft_is_in_set(s1[count], set) == 0)
		count++;
	if (count == finish)
		return (ft_strdup(""));
	while (ft_is_in_set(s1[finish - 1], set) == 0)
		finish--;
	ret = ft_substr(s1, count, (finish - count));
	return (ret);
}
