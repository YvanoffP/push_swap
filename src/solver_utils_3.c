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
