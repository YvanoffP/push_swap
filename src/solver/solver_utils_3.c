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

void	chunk_side_move(t_stack *b, t_chunk chunk)
{
		if (chunk.pos <= chunk.size / 2)
			while (b->front->data != chunk.min && b->front->data != chunk.max)
				rb(b);
		else if (chunk.pos > chunk.size / 2)
			while (b->front->data != chunk.min && b->front->data != chunk.max)
				rrb(b);
}

void	rr_decision(t_stack *a, t_stack *b, t_chunk chunk)
{
	if (chunk.pos <= chunk.size / 2 && chunk.pos != 1)
		rr(a, b);
	else
		ra(a);
}

void    resolve_chunk(t_stack *a, t_stack *b)
{
	t_chunk	chunk;

	chunk_init(&chunk, b);
	chunk.pos = shortest_pos(b->front, chunk.min, chunk.max);
	while (!is_empty(b))
	{
		chunk_side_move(b, chunk);
		if (b->front->data == chunk.min)
		{
			pa(b, a);
			if (is_empty(b))
				break ;
			chunk_init(&chunk, b);
			chunk.pos = shortest_pos(b->front, chunk.min, chunk.max);
			rr_decision(a, b, chunk);
		}
		else if (b->front->data == chunk.max)
		{
			pa(b, a);
			if (is_empty(b))
				break ;
			chunk_init(&chunk, b);
			chunk.pos = shortest_pos(b->front, chunk.min, chunk.max);
		}
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
