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
		else if (a->front->data > a->front->next->data &&
					a->front->data > a->tail->data)
		{
			ra(a);
			if (!is_sorted(a))
				sa(a);
		}
		else if (a->front->data < a->front->next->data &&
					a->front->data < a->tail->data)
		{
			ra(a);
			sa(a);
			rra(a);
		}
		else if (a->front->data > a->front->next->data &&
					a->front->data < a->tail->data)
			sa(a);
		else if (a->front->data < a->front->next->data &&
					a->front->data > a->tail->data)
			rra(a);
	}
}

void	solver_med(t_stack *a, t_stack *b)
{
	int	min_data;
	int	max_data;
	int	median;

	min_data = get_min_data(a->front);
	max_data = get_max_data(a->front);
	median = get_median_data(a, min_data, max_data, (list_size(a->front) / 2));
	move_to(a, b, median);
	if (list_size(a->front) <= 3)
	{
		solver_short(a);
		while (!is_empty(b))
			pa(b, a);
	}
}

void	solver_long(t_stack *a, t_stack *b)
{
	while (list_size(a->front) > 40)
	{
		check_x_data(a, b);
	}
	while (list_size(a->front) > 6)
	{
		check_2_data(a, b);
	}
	solver_med(a, b);
}

void	solver(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (is_rev_sorted(a) && list_size(a->front) > 3)
	{
		while (!is_empty(a))
			pb(a, b);
		while (!is_empty(b))
		{
			if (list_size(b->front) != 1)
				rrb(b);
			pa(b, a);
		}
	}
	else if (list_size(a->front) <= 3)
		solver_short(a);
	else if (list_size(a->front) <= 6)
		solver_med(a, b);
	else if (list_size(a->front) > 6)
		solver_long(a,b);
}
