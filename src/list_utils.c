#include "push_swap.h"

void	display(t_stack *a, t_stack *b)
{
	char	*stack_a;
	char	*stack_b;
	t_node	*node_a;
	t_node	*node_b;

	node_a = a->front;
	node_b = b->front;
	stack_a = "---A---";
	stack_b = "---B---";
	printf("%7s ||| %7s\n", stack_a, stack_b);
	while (node_a != NULL && node_b != NULL)
	{
		printf("%7i ||| %7i\n", node_a->data, node_b->data);
		node_a = node_a->next;
		node_b = node_b->next;
	}
	while (node_a)
	{
		printf("%7i ||| XXXXXXX\n", node_a->data);
		node_a = node_a->next;
	}
	while (node_b)
	{
		printf("XXXXXXX ||| %7i\n", node_b->data);
		node_b = node_b->next;
	}
}

t_node	*new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
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

int list_size(t_node *current_node)
{
	int     count;

	count = 0;
	while (current_node != NULL)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}

void	init_data(t_data *data, t_stack *a)
{
	data->size = list_size(a->front);
	data->min_data = get_min_data(a->front);
	data->max_data = get_max_data(a->front);
	data->median_low = get_median_data(a, data->min_data, data->max_data, (data->size / 3));
	data->median_high = get_median_data(a, data->min_data, data->max_data, (data->size / 3) * 2);
}
