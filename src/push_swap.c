#include "push_swap.h"
void	initb(t_stack *b)
{
	t_stack	*new;
	t_stack	*new_2;

	new = lstnew(20);
	new_2 = lstnew(30);
	b->next = new;
	new->next = new_2;
	new_2->next = NULL;
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = lstnew(10);
	initb(stack_b);
	stack_a = parsing_args(argc, argv);
	print_stack(stack_a);
	ss(&stack_a, &stack_b);
	printf("NEW STACK\n");
	print_stack(stack_a);
	return (0);
}
