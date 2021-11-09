#include "push_swap.h"

int     more_than_one(t_node *check, int data, int count)
{
	if (check->data == data && check->next != NULL)
		return (more_than_one(check->next, data, count + 1));
	if (check->next != NULL)
		count = more_than_one(check->next, data, count);
	if (check->data == data && check->next == NULL)
		count++;
	return (count);
}

void	check_for_dup(t_stack *a)
{
	int     checker;
	t_node  *current_node;

	current_node = a->front;
	checker = more_than_one(current_node, current_node->data, 0);
	while (checker == 1 && current_node->next != NULL)
	{
		checker = more_than_one(current_node, current_node->data, 0);
		current_node = current_node->next;
	}
	if (checker != 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	clear(char **array)
{
	int     i;

	i = 0;
	while (array[i])
	{
			free(array[i]);
			i++;
	}
	free(array);
}

int nb_args(char **arg)
{
	int i;

	i = 0;
	while (arg[i])
		i++;
	return (i - 1);
}
