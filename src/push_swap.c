#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = parsing_args(argc, argv);
	print_stack(stack_a);
	return (0);
}
