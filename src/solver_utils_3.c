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
		if (node->data < next_min_data && node->data > min_data)
			next_min_data = node->data;
		node = node->next;
	}
	return (next_min_data);
}

int	smart_way(t_stack *a, t_data data, int zone, int *step)
{
	int	by_front;
	int	by_tail;

	if (zone == 3)
	{
		by_front = get_by(a->front, data.min_data, data.median_low, 1);
		by_tail = get_by(a->tail, data.min_data, data.median_low, -1);
	}
	if (zone == 2)
	{
		by_front = get_by(a->front, data.median_low, data.median_high, 1);
		by_tail = get_by(a->tail, data.median_low, data.median_high, -1);
	}
	if (zone == 1)
	{
		by_front = get_by(a->front, data.median_high, data.max_data, 1);
		by_tail = get_by(a->tail, data.median_high, data.max_data, -1);
	}
	if (by_front < by_tail)
	{
		*step = by_front;
		return (1);
	}
	else if (by_front > by_tail)
	{
		*step = by_tail;
		return (-1);
	}
	else if (by_front == 0 && by_front == 0)
	{
		*step = 0;
		return (0);
	}
	else
	{
		*step = by_front;
		return (1);
	}
}

void	collect(t_stack *a, t_stack *b, t_data data, int zone)
{
	int	way;
	int	step;

	step = 0;
	way = 1;
	while (way)
	{
		way = smart_way(a, data, zone, &step);
		if (way == 1 && step != 0)
		{
			while (--step)
				ra(a);
			pb(a, b);
			if (list_size(b->front) > 1 && (b->front->data == data.max_data || b->front->data == data.min_data ||
					b->front->data == data.median_low || b->front->data == data.median_high))
				rb(b);
		}
		else if (way == -1 && step != 0)
		{
			while (step--)
				rra(a);
			pb(a, b);
			if (list_size(b->front) > 1 && (b->front->data == data.max_data || b->front->data == data.min_data ||
					b->front->data == data.median_low || b->front->data == data.median_high))
				rb(b);
		}
	}
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
