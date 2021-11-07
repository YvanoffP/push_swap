#include "push_swap.h"

t_node	*new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->front = NULL;
	new->tail = NULL;
	return (new);
}
