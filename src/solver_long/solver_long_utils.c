#include "../push_swap.h"

void    smart_way_decision_long(t_stack *a, t_long *data, int zone)
{
	if (zone == 5)
	{
		data->by_front = get_by(a->front, data->min, data->med_1, 1);
		data->by_tail = get_by(a->tail, data->min, data->med_1, -1);
	}
	if (zone == 4)
	{
		data->by_front = get_by(a->front, data->med_1, data->med_2, 1);
		data->by_tail = get_by(a->tail, data->med_1, data->med_2, -1);
	}
	if (zone == 3)
	{
		data->by_front = get_by(a->front, data->med_2, data->med_3, 1);
		data->by_tail = get_by(a->tail, data->med_2, data->med_3, -1);
	}
	if (zone == 2)
	{
		data->by_front = get_by(a->front, data->med_3, data->med_4, 1);
		data->by_tail = get_by(a->tail, data->med_3, data->med_4, -1);
	}
	if (zone == 1)
	{
		data->by_front = get_by(a->front, data->med_4, data->max, 1);
		data->by_tail = get_by(a->tail, data->med_4, data->max, -1);
	}
}

int	smart_way_long(t_stack *a, t_long data, int zone, int *step)
{
	smart_way_decision_long(a, &data, zone);
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

void	collect_long(t_stack *a, t_stack *b, t_long data, int zone)
{
	int	way;
	int	step;

	step = 0;
	way = 1;
	while (way)
	{
		way = smart_way_long(a, data, zone, &step);
		if (way == 1 && step != 0)
		{
			while (--step)
					ra(a);
			pb(a, b);
			if (list_size(b->front) >= 1 && (b->front->data == data.max || b->front->data == data.min
                    || b->front->data == data.med_1 || b->front->data == data.med_2
                    || b->front->data == data.med_3 || b->front->data == data.med_4))
				rb(b);
		}
		else if (way == -1 && step != 0)
		{
			while (step--)
				rra(a);
			pb(a, b);
			 if (list_size(b->front) >= 1 && (b->front->data == data.max || b->front->data == data.min
                    || b->front->data == data.med_1 || b->front->data == data.med_2
                    || b->front->data == data.med_3 || b->front->data == data.med_4))
				rb(b);
		}
	}
}
