#include "push_swap.h"

void	chunk_init(t_chunk *c, t_stack *b)
{
	c->min = get_min_data(b->front);
	c->max = get_max_data(b->front);
	c->pos = 0;
	c->size = list_size(b->front);
}
