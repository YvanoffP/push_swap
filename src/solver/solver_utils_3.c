#include "../push_swap.h"

int	get_next_min_data(t_node *node, int min_data)
{
	int     next_min_data;

	next_min_data = 2147483647;
	while (node != NULL)
	{
		if (node->data < next_min_data && node->data > min_data)
			next_min_data = node->data;
		node = node->next;
	}
	return (next_min_data);
}

void    resolve_chunk(t_stack *a, t_stack *b)
{
	t_chunk	chunk;

	while (!is_empty(b))
	{
		chunk_init(&chunk, b);
		chunk.pos = shortest_pos(b->front, chunk.min, chunk.max);
		if (chunk.pos <= chunk.size / 2)
			while (b->front->data != chunk.min && b->front->data != chunk.max)
				rb(b);
		else if (chunk.pos > chunk.size / 2)
			while (b->front->data != chunk.min && b->front->data != chunk.max)
				rrb(b);
		if (b->front->data == chunk.min)
		{
			pa(b, a);
			ra(a);
		}
		else if (b->front->data == chunk.max)
			pa(b, a);
	}
}

int	smart_way_long(t_stack *a, t_long data, int *step)
{
	data.by_front = get_by(a->front, data, 1);
	data.by_tail = get_by(a->tail, data, -1);
	if (data.by_front < data.by_tail)
	{
		*step = data.by_front;
		return (1);
	}
	else if (data.by_front > data.by_tail)
	{
		*step = data.by_tail;
		return (-1);
	}
	else if (data.by_front == 0 && data.by_front == 0)
	{
		*step = 0;
		return (0);
	}
	else
	{
		*step = data.by_front;
		return (1);
	}
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

void	collect_long(t_stack *a, t_stack *b, t_long data)
{
	int	way;
	int	step;
	int	pute;

	step = 0;
	way = 1;
	pute = data.high;
	while (way)
	{
		way = smart_way_long(a, data, &step);
		if (way == 1 && step != 0)
		{
			while (--step)
				ra(a);
			pb(a, b);
			if (list_size(b->front) >= 1 && (b->front->data == data.high
						|| b->front->data == pute))
			{
				if (b->front->data == pute)
					pute = get_next_min_data(a->front, data.high);
				rb(b);
			}
		}
		else if (way == -1 && step != 0)
		{
			while (step--)
				rra(a);
			pb(a, b);
			if (list_size(b->front) >= 1 && (b->front->data == data.high
						|| b->front->data == pute))
			{
				if (b->front->data == pute)
					pute = get_next_min_data(a->front, data.low);
				rb(b);
			}
		}
	}
}
