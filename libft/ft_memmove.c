/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:52:52 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/11 14:56:52 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destcopy;
	const unsigned char	*srccopy;

	destcopy = (unsigned char *)dest;
	srccopy = (const unsigned char *)src;
	if (dest == src)
		return (dest);
	if (srccopy < destcopy)
	{
		while (n != 0)
		{
			n--;
			*(destcopy + n) = *(srccopy + n);
		}
		return (dest);
	}
	while (n != 0)
	{
		n--;
		*destcopy++ = *srccopy++;
	}
	return (dest);
}

/*int main()
{
        unsigned char d[] = "gvedgfefqezfzefe";
        const unsigned char s[] = "salutest";

        printf("%s\n", (char)memmove(d, s, 7));
        printf("%s\n", (char)ft_memmove(d, s, 7));
}*/
