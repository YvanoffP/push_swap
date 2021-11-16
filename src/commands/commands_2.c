/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:05:21 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/11/16 16:05:29 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	if (a->front->data != a->tail->data && a->front != NULL && a->tail != NULL)
	{
		a->front->prev = a->tail;
		a->tail->next = a->front;
		a->front = a->front->next;
		a->front->prev->next = NULL;
		a->front->prev = NULL;
		a->tail = a->tail->next;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *b)
{
	if (b->front->data != b->tail->data && b->front != NULL && b->tail != NULL)
	{
		b->front->prev = b->tail;
		b->tail->next = b->front;
		b->front = b->front->next;
		b->front->prev->next = NULL;
		b->front->prev = NULL;
		b->tail = b->tail->next;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	if (b->front->data != b->tail->data && b->front != NULL && b->tail != NULL)
	{
		b->front->prev = b->tail;
		b->tail->next = b->front;
		b->front = b->front->next;
		b->front->prev->next = NULL;
		b->front->prev = NULL;
		b->tail = b->tail->next;
	}
	if (a->front->data != a->tail->data && a->front != NULL && a->tail != NULL)
	{
		a->front->prev = a->tail;
		a->tail->next = a->front;
		a->front = a->front->next;
		a->front->prev->next = NULL;
		a->front->prev = NULL;
		a->tail = a->tail->next;
	}
	write(1, "rr\n", 3);
}
