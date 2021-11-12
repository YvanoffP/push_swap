#include "push_swap.h"

int	get_pos_data(t_node *node, int min_data)
{
	int	pos;

	pos = 0;
	while (node != NULL)
	{
		if (node->data == min_data)
			return (pos);
		pos++;
		node = node->next;
	}
	exit(0);
}

int	get_next_min_data(t_node *node, int min_data)
{
	int     next_min_data;

	next_min_data = 2147483647;
	while (node != NULL)
	{
		if (node->data < next_min_data && node->data != min_data)
			next_min_data = node->data;
		node = node->next;
	}
	return (next_min_data);
}
