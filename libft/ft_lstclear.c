/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:58:23 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/10/14 21:11:00 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*t_tmp;

	if (!lst || !(del))
		return ;
	tmp = *lst;
	while (tmp)
	{
		t_tmp = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = t_tmp;
	}
	*lst = NULL;
}
