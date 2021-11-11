#include "push_swap.h"

int	get_median_data(t_stack *stack, int median, int max, int nb_loop)
{
	t_node	*node;
	int		new_med;

	node = stack->front;
	new_med = max;
	while (node != NULL)
	{
		if (node->data < max && node->data > median && node->data < new_med)
			new_med = node->data;
		node = node->next;
	}
	if (nb_loop > 1)
		return (get_median_data(stack, new_med, max, --nb_loop));
	else
		return (new_med);
}
