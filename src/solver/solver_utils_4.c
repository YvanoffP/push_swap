/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:39:05 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/11/16 17:47:27 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	data->low = get_median_data(a, data->min, data->max,
			(data->size / nb_chunk) * data->mult);
	data->mult -= 1;
}

void	collect_long(t_stack *a, t_stack *b, t_long data)
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
			if (collect_long_decision(b, data))
				rb(b);
		}
		else if (data.way == -1 && step != 0)
		{
			while (step--)
				rra(a);
			pb(a, b);
			if (collect_long_decision(b, data))
				rb(b);
		}
	}
}

int	collect_long_decision(t_stack *b, t_long data)
{
	if (list_size(b->front) > 1 && (b->front->data == data.max
			|| b->front->data == data.min || b->front->data == data.low
			|| b->front->data == data.high))
		return (1);
	return (0);
}

int	determine_chunk(t_stack *a)
{
	int	size;
	int	chunk;

	chunk = 1;
	size = list_size(a->front);
	if (size < 25)
		return (chunk);
	else if (size <= 50)
		return (++chunk);
	else if (size <= 100)
		return (4);
	else if (size <= 200)
		return (5);
	else if (size <= 300)
		return (6);
	else if (size <= 400)
		return (7);
	else if (size <= 500)
		return (8);
	else if (size <= 1000)
		return (12);
	else if (size >= 1000)
		return (16);
	exit(0);
}
