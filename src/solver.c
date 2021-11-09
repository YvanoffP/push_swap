#include "push_swap.h"

int	sort_checker(t_stack *a)
{
	t_node	*check;

	check = a->front;
	while (check->next != NULL)
	{
		if (check->data < check->next->data && check->next != NULL)
			check = check->next;
		else
			return (-1);
	}
	return (1);
}
