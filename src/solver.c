#include "push_swap.h"

void    solver_short(t_stack *a)
{
	if (list_size(a->front) == 2 && !is_sorted(a))
		sa(a);
	else if (list_size(a->front) == 3 && !is_sorted(a))
	{
		if (is_rev_sorted(a))
		{
			sa(a);
			rra(a);
		}
		else if (a->front->data > a->front->next->data && a->front->data > a->tail->data)
		{
			ra(a);
			if (!is_sorted(a))
				sa(a);
		}
		else if (a->front->data < a->front->next->data && a->front->data < a->tail->data)
		{
			ra(a);
			sa(a);
			rra(a);
		}
	}
}

void	solver(t_stack *a, t_stack *b)
{
	if (is_rev_sorted(a) && list_size(a->front) > 3)
	{
		while (!is_empty(a))
			pb(a, b);
		while (!is_empty(b))
		{
			if (list_size(b->front) <= 1)
				rrb(b);
			pa(b, a);
		}
	}
	if (list_size(a->front) <= 3)
		solver_short(a);
	else
		(void)b;
}
