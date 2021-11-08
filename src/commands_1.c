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
	if (b->front == NULL)
		return ;
	if (a->front == NULL && a->tail == NULL)
	{
		a->front = b->front;
		a->tail = b->front;
		b->front = b->front->next;
		b->front->prev = NULL;
		a->front->next = NULL;
	}
	else if (a->front && a->tail && b->front->next)
	{
		a->front->prev = b->front;
		b->front = b->front->next;
		b->front->prev = NULL;
		a->front->prev->next = a->front;
		a->front = a->front->prev;
	}
	else if (!b->front->next)
	{
		a->front->prev = b->front;
		b->front->next = a->front;
		a->front = a->front->prev;
		b->front = NULL;
		b->tail = NULL;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->front == NULL)
		return ;
	if (b->front == NULL && b->tail == NULL)
	{
		b->front = a->front;
		b->tail = a->front;
		a->front = a->front->next;
		a->front->prev = NULL;
		b->front->next = NULL;
	}
	else if (b->front && b->tail && a->front->next)
	{
		b->front->prev = a->front;
		a->front = a->front->next;
		a->front->prev = NULL;
		b->front->prev->next = b->front;
		b->front = b->front->prev;
	}
	else if (!a->front->next)
	{
		b->front->prev = a->front;
		a->front->next = b->front;
		b->front = b->front->prev;
		a->front = NULL;
		a->tail = NULL;
	}
}
