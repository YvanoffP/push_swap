#include "../push_swap.h"

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

void	set_median_low(t_long *data, t_stack *a, int nb_chunk)
{
	if (data->high != data->max)
		data->to_front = get_next_min_data(a->front, data->high);
	if (data->mult == 0)
	{
		data->low = data->min;
		return ;
	}
	data->low = get_median_data(a, data->min, data->max, (data->size / nb_chunk) * data->mult);
	data->mult -= 1;
}

void collect_long(t_stack *a, t_stack *b, t_long data)
{
	int	step;

	data.way = 1;
	step = 0;
	while (data.way)
	{
		data.way = smart_way_long(a, data, &step);
		if (data.way == 1 && step != 0)
		{
			while (--step)
				ra(a);
			pb(a, b);
			if (list_size(b->front) > 1 && (b->front->data == data.max || b->front->data == data.min
						|| b->front->data == data.low || b->front->data == data.high))
				rb(b);
		}
		else if (data.way == -1 && step != 0)
		{
			while (step--)
				rra(a);
			pb(a, b);
			if (list_size(b->front) > 1 && (b->front->data == data.max || b->front->data == data.min
					|| b->front->data == data.low || b->front->data == data.high))
				rb(b);
		}
	}
}
