#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parsing_args(argc, argv);
	b = malloc(sizeof(t_stack));
	display(a, b);

	pb(a, b);
	display(a, b);

	pb(a, b);
	display(a, b);

	pb(a, b);
	display(a, b);

	printf("%i\n", a->front->data);

	free(a);
	free(b);
	return (0);
}
