#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct  s_stack
{
        int             nb;
        struct s_stack  *next;
}               t_stack;

// Parsing
t_stack *parsing_args(int argc, char **argv);
t_stack *parsing_multi_args(char **argv);
t_stack *parsing_string(char **argv);

// List chain utils
void    print_stack(t_stack     *stack);
t_stack  *lstlast(t_stack *lst);
t_stack  *lstnew(int content);
void    lstadd_front(t_stack **alst, t_stack *new);
void    lstadd_back(t_stack **alst, t_stack *new);
int     lstsize(t_stack *lst);

#endif
