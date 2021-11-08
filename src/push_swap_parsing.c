#include "push_swap.h"

void	clear(char **array)
{
	int	i;
	i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_stack	*parsing_string(char **argv)
{
    t_stack *a;
    t_node  *temp;
    int     i;
    char    **tmp;

    a = new_stack();
    i = 0;
    tmp = ft_split(argv[1], ' ');
    if (!tmp)
		return (0);
    while (tmp[i])
        i++;
    i -= 1;
	while (i >= 0)
	{
		temp = new_node(ft_atoi(tmp[i]));
		if (a->front == NULL)
			a->tail = temp;
		else
		{
			temp->next = a->front;
			a->front->prev = a->front;
		}
		a->front = temp;
		i--;
	}
	clear(tmp);
	return (a);
}

t_stack	*parsing_multi_args(char **argv)
{
	t_stack *a;
	t_node  *temp;
	int     i;

    a = new_stack();
	i = 1;
	while (argv[i])
		i++;
	i -= 1;
	while (i > 0)
	{
		temp = new_node(ft_atoi(argv[i]));
		if (a->front == NULL)
			a->tail = temp;
		else
		{
			a->front->prev = temp;
			temp->next = a->front;
		}
		a->front = temp;
		i--;
	}
	return (a);
}

t_stack	*parsing_args(int argc, char **argv)
{
	if (argc == 2)
		return (parsing_string(argv));
	else if (argc > 2)
		return (parsing_multi_args(argv));
	else
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (0);
}
