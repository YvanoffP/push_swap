/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:07:09 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/11/16 16:09:05 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*void	display(t_stack *a, t_stack *b)
{
	char	*stack_a;
	char	*stack_b;
	t_node	*node_a;
	t_node	*node_b;

	node_a = a->front;
	node_b = b->front;
	stack_a = "---A---";
	stack_b = "---B---";
	printf("%7s ||| %7s\n", stack_a, stack_b);
	while (node_a != NULL && node_b != NULL)
	{
		printf("%7i ||| %7i\n", node_a->data, node_b->data);
		node_a = node_a->next;
		node_b = node_b->next;
	}
	while (node_a)
	{
		printf("%7i ||| XXXXXXX\n", node_a->data);
		node_a = node_a->next;
	}
	while (node_b)
	{
		printf("XXXXXXX ||| %7i\n", node_b->data);
		node_b = node_b->next;
	}
}*/

t_node	*new_node(int data)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*new_stack(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	new->front = NULL;
	new->tail = NULL;
	return (new);
}

int	list_size(t_node *current_node)
{
	int	count;

	count = 0;
	while (current_node != NULL)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}
