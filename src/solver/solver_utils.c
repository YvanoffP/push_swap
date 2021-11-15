#include "../push_swap.h"

int     is_sorted(t_stack *a)
{
	t_node  *check;

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
	t_node  *check;

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

int     is_empty(t_stack *b)
{
    if (b->front == NULL && b->tail == NULL)
		return (1);
    return (0);
}

int get_min_data(t_node *node)
{
	int min_data;

	min_data = node->data;
	while (node != NULL)
	{
		if (min_data > node->data)
			min_data = node->data;
		node = node->next;
	}
	return (min_data);
}

int get_max_data(t_node *node)
{
	int max_data;

	max_data = node->data;
	while (node != NULL)
	{
		if (max_data < node->data)
			max_data = node->data;
		node = node->next;
	}
	return (max_data);
}
