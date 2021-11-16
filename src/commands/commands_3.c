/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:05:49 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/11/16 16:06:37 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *a)
{
	if (a->front != a->tail && a->front != NULL && a->tail != NULL)
	{
		a->tail->next = a->front;
		a->front->prev = a->tail;
		a->tail = a->tail->prev;
		a->tail->next->prev = NULL;
		a->tail->next = NULL;
		a->front = a->front->prev;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *b)
{
	if (b->front != b->tail && b->front != NULL && b->tail != NULL)
	{
		b->tail->next = b->front;
		b->front->prev = b->tail;
		b->tail = b->tail->prev;
		b->tail->next->prev = NULL;
		b->tail->next = NULL;
		b->front = b->front->prev;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	if (b->front != b->tail && b->front != NULL && b->tail != NULL)
	{
		b->tail->next = b->front;
		b->front->prev = b->tail;
		b->tail = b->tail->prev;
		b->tail->next->prev = NULL;
		b->tail->next = NULL;
		b->front = b->front->prev;
	}
	if (a->front != a->tail && a->front != NULL && a->tail != NULL)
	{
		a->tail->next = a->front;
		a->front->prev = a->tail;
		a->tail = a->tail->prev;
		a->tail->next->prev = NULL;
		a->tail->next = NULL;
		a->front = a->front->prev;
	}
	write(1, "rrr\n", 4);
}

void	set_front_tail(t_stack *nullme)
{
	nullme->front = NULL;
	nullme->tail = NULL;
}

void	push_shortener(t_stack *a, t_stack *b)
{
	a->front->prev = b->front;
	b->front->next = a->front;
	a->front = a->front->prev;
	set_front_tail(b);
}
