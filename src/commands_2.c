#include "push_swap.h"

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
	}
	else
		write(1, "Rotate a failed\n", 17);
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
