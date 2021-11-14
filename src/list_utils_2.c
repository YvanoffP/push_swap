#include "push_swap.h"

void	chunk_init(t_chunk *c, t_stack *b)
{
	c->min = get_min_data(b->front);
	c->max = get_max_data(b->front);
	c->pos = 0;
	c->size = list_size(b->front);
}

void	long_init(t_long *data, t_stack *a)
{
	data->size = list_size(a->front);
	data->min = get_min_data(a->front);
	data->max = get_max_data(a->front);
	data->med_1 = get_median_data(a, data->min, data->max, (data->size / 5));
	data->med_2 = get_median_data(a, data->min, data->max, (data->size / 5) * 2);
	data->med_3 = get_median_data(a, data->min, data->max, (data->size / 5) * 3);
	data->med_4 = get_median_data(a, data->min, data->max, (data->size / 5) * 4);
	data->by_tail = 0;
	data->by_front = 0;
}
