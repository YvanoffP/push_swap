/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:09:17 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/11/16 16:09:23 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	chunk_init(t_chunk *c, t_stack *b)
{
	c->min = get_min_data(b->front);
	c->max = get_max_data(b->front);
	c->pos = 0;
	c->size = list_size(b->front);
}

void	long_init(t_long *data, t_stack *a, int nb_chunk)
{
	data->size = list_size(a->front);
	data->min = get_min_data(a->front);
	data->max = get_max_data(a->front);
	data->low = 0;
	data->high = 0;
	data->by_tail = 0;
	data->by_front = 0;
	data->mult = nb_chunk - 1;
	data->zone = 0;
	data->to_front = 0;
	data->way = 0;
}
