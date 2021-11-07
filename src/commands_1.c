#include "push_swap.h"

void	sa(t_stack *a)
{
	t_node	*swp;

	if (a->front && a->front->next)
	{
		swp = new_node(a->front->next->data);
		a->front->next->data = a->front->data;
		a->front->data = swp->data;
	}
	else
		write(1, "sa failed\n", 11);
}

void	sb(t_stack *b)
{
	t_node	*swp;

	if (b->front && b->front->next)
	{
		swp = new_node(b->front->next->data);
		b->front->next->data = b->front->data;
		b->front->data = swp->data;
	}
	else
		write(1, "sb failed\n", 11);
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->front && a->front->next
			&& b->front && b->front->next)
	{
		sa(a);
		sb(b);
	}
	else
		write(1, "Swap failed\n", 13);
}

void	pa(t_stack *b, t_stack *a)
{
	t_node	*node_push;

	if (b->front)
	{
		node_push = new_node(b->front->data);
		if (a->front == NULL)
			a->tail = node_push;
		else if (a->front)
			node_push->next = a->front;
		a->front = node_push;
		b->front = b->front->next;
	}
	else
		write(1, "Push failed\n", 13);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node_push;

	if (a->front)
	{
		node_push = new_node(a->front->data);
		if (b->front == NULL)
			b->tail = node_push;
		else if (b->front)
			node_push->next = b->front;
		b->front = node_push;
		a->front = a->front->next;
	}
	else
		write(1, "Push failed\n", 13);
}
