#include "push_swap.h"

t_stack	*sa(t_stack *a)
{
	t_stack	*swp;

	swp = a->next;
	a->next = swp->next;
	swp->next = a;
	return (swp);
}

t_stack	*sb(t_stack *b)
{
	t_stack	*swp;

	swp = b->next;
	b->next = swp->next;
	swp->next = b;
	return (swp);
}

void	ss(t_stack **a, t_stack **b)
{
	*a = sa(*a);
	*b = sb(*b);
}

void	pa(t_stack **a, t_stack **b)
{

}
