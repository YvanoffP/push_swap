#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct  s_node
{
        int             data;
        struct s_node   *prev;
        struct s_node   *next;
}               t_node;

typedef struct  s_stack
{
    t_node  *front;
    t_node  *tail;
}               t_stack;

// Parsing
t_stack *parsing_args(int argc, char **argv);
t_stack *parsing_multi_args(char **argv);
t_stack *parsing_string(char **argv);
void    clear(char **array);
void    check_for_dup(t_stack *a);
int     nb_args(char **arg);
int     more_than_one(t_node *check, int data, int count);

// List chain utils
void    display(t_stack *a, t_stack *b);
t_node  *new_node(int data);
t_stack *new_stack(void);

// Solver
int     is_empty(t_stack *b);
int     is_sorted(t_stack *a);
int     is_rev_sorted(t_stack *b);
int     guit_recursive(int data, int count, t_node *current_node);
void    solver(t_stack *a, t_stack *b);

//Commands
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *b, t_stack *a);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);
void    set_front_tail(t_stack *nullme);

#endif
