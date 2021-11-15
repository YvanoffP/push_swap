#include "../push_swap.h"

int	get_median_data(t_stack *stack, int min_data, int max, int nb_loop)
{
	t_node	*node;
	int		new_med;

	node = stack->front;
	new_med = max;
	while (node != NULL)
	{
		if (node->data < max && node->data > min_data && node->data < new_med)
			new_med = node->data;
		node = node->next;
	}
	if (nb_loop > 1)
		return (get_median_data(stack, new_med, max, --nb_loop));
	else
		return (new_med);
}

void	move_to(t_stack	*a, t_stack *b, int median)
{
	int		count;
	int		count_lower_med;
	int		size;

	count = 0;
	count_lower_med = 0;
	size = list_size(a->front);
	while (count < size && count_lower_med < size / 2)
	{
		if (a->front->data < median)
		{
			pb(a, b);
			sort_b(b, a);
			count_lower_med++;
		}
		else
			ra(a);
		count++;
	}
}

void	sort_b(t_stack *b, t_stack *a)
{
	int search_pos;
	int count;

	if (b->front != NULL && b->tail != NULL)
	{
		if (b->front->data < b->tail->data)
			rb(b);
		else
		{
			count = 0;
			search_pos = guit_recursive(b->front->data, 0, b->front);
			if (search_pos > 1)
				pa(b, a);
			while (count++ < search_pos)
			{
				if (search_pos <= 1)
					sb(b);
				rb(b);
			}
			if (search_pos > 1)
				pb(a, b);
			while (search_pos-- > 0)
				rrb(b);
		}
	}
}

int	guit_recursive(int data, int count, t_node *current_node)
{
	if (current_node->next == NULL)
		return (count);
	if (data < current_node->next->data)
			return (guit_recursive(data, count + 1, current_node->next));
	return (count);
}

int get_by(t_node *node, int lower_bound, int higher_bound, int from)
{
	int i;

	i = 1;
	while (node != NULL && from == 1)
	{
		if (node->data >= lower_bound && node->data <= higher_bound)
			return (i);
		i++;
		node = node->next;
	}
	while (node != NULL && from == -1)
	{
		if (node->data >= lower_bound && node->data <= higher_bound)
			return (i);
		i++;
		node = node->prev;
	}
	return (0);
}
