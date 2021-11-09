#include "push_swap.h"

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

int     is_rev_sorted(t_stack *b)
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

int     guit_recursive(int data, int count, t_node *current_node)
{
	if (data < current_node->next->data)
		return (guit_recursive(data, count + 1, current_node->next));
	return (count);
}
