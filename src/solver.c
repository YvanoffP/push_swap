#include "push_swap.h"

static void	solving_a(t_stack *a, t_stack *b)
{

	if (a->front->next != NULL)
	{
		if (a->front->data > a->front->next->data)
		{
			if (a->front->data > a->tail->data)
				rra(a);
			else
				sa(a);
		}
		if (a->front->data < a->front->next->data)
		{
			if (a->front->data > a->tail->data)
				rra(a);
			else
				pb(a, b);
		}
	}
	else
		pb(a, b);
}

static void	sort_b(t_stack *b)
{
	int	search_pos;
	int	count;

	if (!is_rev_sorted(b) && b->front != NULL && b->tail != NULL)
	{
		if (b->front->data < b->tail->data)
			rb(b);
		else
		{
			count = 0;
			search_pos = guit_recursive(b->front->data, 0, b->front);
			while (count++ < search_pos)
			{
				sb(b);
				rb(b);
			}
			while (search_pos-- > 0)
				rrb(b);
		}
	}
}

static void	empty_b_in_a(t_stack *a, t_stack *b)
{
	while (!is_empty(b))
		pa(b, a);
}

void	solver(t_stack *a, t_stack *b)
{
	while (!is_sorted(a))
	{
		while (!is_empty(a))
		{
			solving_a(a, b);
			sort_b(b);
		}
		empty_b_in_a(a, b);
	}
}
