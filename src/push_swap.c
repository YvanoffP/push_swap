#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parsing_args(argc, argv);
	b = new_stack();

	solver(a, b);

	free(a);
	free(b);
	return (0);
}
