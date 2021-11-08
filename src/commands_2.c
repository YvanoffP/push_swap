#include "push_swap.h"

void	ra(t_stack *a)
{
	int	tmp;

	tmp = 0;
	if (a->front->data != a->tail->data && a->front != NULL && a->tail != NULL)
	{
		tmp = a->front->data;
		a->front->data = a->tail->data;
		a->tail->data = tmp;
	}
	else
		write(1, "Rotate a failed\n", 17);
}

void	rb(t_stack *b)
{
	int	tmp;

	tmp = 0;
	if (b->front->data != b->tail->data && b->front != NULL && b->tail != NULL)
	{
		tmp = b->front->data;
		b->front->data = b->tail->data;
		b->tail->data = tmp;
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
