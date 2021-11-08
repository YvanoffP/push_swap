#include "push_swap.h"

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
	}
	else
		write(1, "Reverse rotate a failed\n", 24);
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
	}
	else
		write(1, "Reverse rotate b failed\n", 24);
}
void    rrr(t_stack *a, t_stack *b)
{
	if (a->front != a->tail && b->front != b->tail)
	{
		rra(a);
		rrb(b);
	}
	else
		write(1, "Reverse rotate both failed\n", 27);
}
