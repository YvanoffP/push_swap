#include "push_swap.h"

void	check_2_data(t_stack *a, t_stack *b)
{
	int         flag;
    int         size;
    t_min_data	*min;

	flag = 0;
	min = parse_next_mins(a, 2);
	size = list_size(a->front);
	if (min->pos >= size / 2 && min->next->pos >= size / 2)
		while (a->front->data != min->data)
		{
			if (a->front->data == min->next->data)
			{
				flag = 1;
				pb(a, b);
			}
			if (a->front->data != min->data)
				rra(a);
		}
	else if (min->pos <= size / 2 && min->next->pos <= size / 2)
		while (a->front->data != min->data)
		{
			if (a->front->data == min->next->data)
			{
				flag = 1;
				pb(a, b);
			}
			if (a->front->data != min->data)
				ra(a);
		}
	else if (min->pos >= size / 2)
		while (a->front->data != min->data)
		{
			if (a->front->data == min->next->data)
			{
				flag = 1;
				pb(a, b);
			}
			if (a->front->data != min->data)
				rra(a);
		}
	else if (min->pos < size / 2)
		while (a->front->data != min->data)
		{
			if (a->front->data == min->next->data)
			{
				flag = 1;
				pb(a, b);
			}
			if (a->front->data != min->data)
				ra(a);
		}
	pb(a, b);
	if (flag == 1)
		sb(b);
}

void	check_x_data(t_stack *a, t_stack *b)
{
	int	how_many;
	int	size;
	t_min_data	*mins;
	t_min_data	*mins_head;

	size = list_size(a->front);
	mins = parse_next_mins(a, 10);
	mins_head = mins;
	if (mins->data <= size / 2)
	{
		how_many = get_how_many_data(mins, 1, 1, size / 2);
		if (how_many <= 2)
		{
			check_2_data(a, b);  // PENSER A FREE
		}
		else
			collect_on_way(a, b, how_many, mins_head);
	}
	else if (mins->data > size / 2)
	{
		how_many = get_how_many_data(mins, -1, -1, size / 2);
		if (how_many >= -2)
		{
			check_2_data(a, b);
		}
		else
			collect_on_way(a, b, how_many, mins_head);
	}
}

void	collect_on_way(t_stack *a, t_stack *b, int how_many, t_min_data *mins)
{
	while (how_many != 0)
	{
		if (a->front->data == mins->data)
		{
			pb(a, b);
			if (how_many > 0)
				how_many--;
			else
				how_many++;
			mins = mins->next;
		}
		else
		{
			if (how_many > 0)
				ra(a);
			else
				rra(a);
		}
	}
}
