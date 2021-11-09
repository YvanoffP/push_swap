#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*check;

	check = a->front;
	if (a->front == NULL || a->tail == NULL)
		return (0);
	while (check->next != NULL)
	{
		if (check->data < check->next->data)
			check = check->next;
		else
			return (0);
	}
	return (1);
}

int	is_rev_sorted(t_stack *b)
{
	t_node	*check;

	check = b->front;
	if (b->front == NULL || b->tail == NULL)
		return (0);
	while (check->next != NULL)
	{
		if (check->data > check->next->data)
			check = check->next;
		else
			return (0);
	}
	return (1);
}

int	is_empty(t_stack *b)
{
	if (b->front == NULL && b->tail == NULL)
		return (1);
	return (0);
}

int	guit_recursive(int data, int count, t_node *current_node)
{
	if (data < current_node->next->data)
		return (guit_recursive(data, count + 1, current_node->next));
	return (count);
}

void	solver(t_stack *a, t_stack *b)
{
	int	search_pos;
	int	count;
	while (!is_sorted(a))
	{
		while (!is_empty(a))
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
			if (!is_rev_sorted(b))
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
		while (!is_empty(b))
			pa(b, a);
	}
}
