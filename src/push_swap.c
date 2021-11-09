#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	i = 0;
	a = parsing_args(argc, argv);
	b = new_stack();

	i = sort_checker(a);
	printf("List sorted = %i\n", i);
	display(a, b);

	free(a);
	free(b);
	return (0);
}
