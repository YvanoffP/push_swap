#include "push_swap.h"

void	ra(t_stack *a)
{
	t_node	*tmp;

	if (a->front != a->tail)
	{
		tmp = new_node(a->front->data);
		tmp->prev = a->tail;
		a->front = a->front->next;
		a->tail->next = tmp;
		a->tail = tmp;
	}
	else
		write(1, "Rotate a failed\n", 17);
}

void	rb(t_stack *b)
{
	t_node	*tmp;

	if (b->front != b->tail)
	{
		tmp = new_node(b->front->data);
		tmp->prev = b->tail;
		b->front = b->front->next;
		b->tail->next = tmp;
		b->tail = tmp;
	}
	else
		write(1, "Rotate b failed\n", 17);
}
void	rr(t_stack *a, t_stack *b)
{
	if (a->front != a->tail && b->front != b->tail)
	{
		ra(a);
		rb(b);
	}
	else
		write(1, "Rotate both failed\n", 20);
}
