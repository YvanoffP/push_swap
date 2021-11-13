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

int     get_next_min_data(t_node *node, int min_data)
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

t_min_data	*parse_next_mins(t_stack *a, int how_many)
{
	t_min_data	*new;
	t_min_data	*tmp;

	new = new_min_data(get_min_data(a->front));
	new->pos = get_pos_data(a->front, new->data) + 1;
	tmp = new;
	while (--how_many > 0)
	{
		add_back(&new, a, get_next_min_data(a->front, tmp->data));
		tmp = tmp->next;
	}
	return (new);
}

int	get_how_many_data(t_min_data *min, int dir, int loop, int stack_half)
{
	if (dir == 1)
	{
		if (min->next == NULL)
			return (loop);
		else if (min->pos < min->next->pos && min->pos <= stack_half && min->next->pos <= stack_half)
			return (get_how_many_data(min->next, 1, loop + 1, stack_half));
	}
	else if (dir == -1)
	{
		if (min->next == NULL)
			return (loop);
		else if (min->pos > min->next->pos && min->pos >= stack_half && min->next->pos >= stack_half)
			return (get_how_many_data(min->next, -1, loop - 1, stack_half));
	}
	return (loop);
}
