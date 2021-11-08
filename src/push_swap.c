#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parsing_args(argc, argv);
	b = new_stack();
	display(a, b);

	ra(a);
	display(a, b);

	pb(a, b);
	display(a, b);

	pb(a, b);
	display(a, b);

	rrb(b);
	display(a, b);

	rrr(a, b);
	display(a, b);

	free(a);
	free(b);
	return (0);
}
