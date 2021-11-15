#include "../push_swap.h"

void	sa(t_stack *a)
{
	int	tmp;

	tmp = 0;
	if (a->front == a->tail)
		return ;
	else if (a->front && a->front->next)
	{
		tmp = a->front->data;
		a->front->data = a->front->next->data;
		a->front->next->data = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b)
{
	int	tmp;

	tmp = 0;
	if (b->front == b->tail)
		return ;
	else if (b->front && b->front->next)
	{
		tmp = b->front->data;
		b->front->data = b->front->next->data;
		b->front->next->data = tmp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->front && a->front->next
			&& b->front && b->front->next)
	{
		sa(a);
		sb(b);
	}
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
		set_front_tail(b);
	}
	write(1, "pa\n", 3);
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
		set_front_tail(a);
	}
	write(1, "pb\n", 3);
}
