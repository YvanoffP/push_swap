#include "push_swap.h"

int	shortest_pos(t_node *node, int min, int max)
{
	int	i;

	i = 1;
	while (node != NULL)
	{
		if (node->data == min || node->data == max)
			return (i);
		i++;
		node = node->next;
	}
	return (0);
}

void	smart_way_decision(t_stack *a, t_data *data, int zone)
{
	if (zone == 3)
	{
		data->by_front = get_by(a->front, data->min_data, data->median_low, 1);
		data->by_tail = get_by(a->tail, data->min_data, data->median_low, -1);
	}
	if (zone == 2)
	{
		data->by_front = get_by(a->front, data->median_low, data->median_high, 1);
		data->by_tail = get_by(a->tail, data->median_low, data->median_high, -1);
	}
	if (zone == 1)
	{
		data->by_front = get_by(a->front, data->median_high, data->max_data, 1);
		data->by_tail = get_by(a->tail, data->median_high, data->max_data, -1);
    }
}
