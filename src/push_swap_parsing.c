#include "push_swap.h"

void    print_stack(t_stack     *stack)
{
    while (stack != NULL)
    {
		printf("%i\n", stack->nb);
        stack = stack->next;
    }
}

t_stack	*parsing_string(char **argv)
{
        char    **args_tab;
        int     nb_args;
        int     index;
        t_stack	*stack;
		t_stack	*tmp;

        nb_args = 0;
        index = 0;
        args_tab = ft_split(argv[1], ' ');
        if (!args_tab)
			return (0);
		while (args_tab[nb_args])
			nb_args++;
		stack = lstnew(ft_atoi(args_tab[index++]));
		while (index < nb_args)
		{
			tmp = lstnew(ft_atoi(args_tab[index++]));
			lstadd_back(&stack, tmp);
		}
		return(stack);
}

t_stack	*parsing_multi_args(char **argv)
{
        int     nb_args;
        int     index_args;
        t_stack	*stack;
		t_stack	*tmp;

        nb_args = 0;
        index_args = 1;
        while (argv[nb_args])
			nb_args++;
		stack = lstnew(ft_atoi(argv[index_args++]));
        while (index_args < nb_args)
		{
			tmp = lstnew(ft_atoi(argv[index_args++]));
			lstadd_back(&stack, tmp);
		}
        return (stack);
}

t_stack	*parsing_args(int arg_count, char **argvals)
{
        t_stack	*a;

        if (arg_count == 2)
			a = parsing_string(argvals);
        else if (arg_count > 2)
			a = parsing_multi_args(argvals);
        else
		{
			write (1, "error", 5);
			a = NULL;
			return (a);
		}
        return (a);
}
