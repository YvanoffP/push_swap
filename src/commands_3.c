#include "push_swap.h"

void	rra(t_stack *a)
{
	t_node  *tmp;

	if (a->front != a->tail)
	{
		tmp = new_node(a->tail->data);
		tmp->next = a->front;
		a->tail = a->tail->prev;
		a->tail->next = NULL;
		a->front->prev = tmp;
		a->front = tmp;
	}
	else
		write(1, "Reverse rotate a failed\n", 24);
}

void	rrb(t_stack *b)
{
	t_node  *tmp;

	if (b->front != b->tail)
	{
		tmp = new_node(b->tail->data);
		tmp->next = b->front;
		b->tail = b->tail->prev;
		b->tail->next = NULL;
		b->front->prev = tmp;
		b->front = tmp;
	}
	else
		write(1, "Reverse rotate b failed\n", 24);
}
void    rrr(t_stack *a, t_stack *b)
{
	if (a->front != a->tail && b->front != b->tail)
	{
		ra(a);
		rb(b);
	}
	else
		write(1, "Reverse rotate both failed\n", 27);
}
