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

typedef struct  s_min_data
{
    int         data;
    int         pos;
    struct s_min_data  *next;
}               t_min_data;

// Parsing
t_stack *parsing_args(int argc, char **argv);
t_stack *parsing_multi_args(char **argv);
t_stack *parsing_string(char **argv);
void    clear(char **array);
void    check_for_dup(t_stack *a);
int     nb_args(char **arg);
int     more_than_one(t_node *check, int data, int count);
int     check_error_args(char **argv);
int     only_whitespace(char **argv);

// List chain utils
void        display(t_stack *a, t_stack *b);
int         list_size(t_node *current_node);
t_node      *new_node(int data);
t_stack     *new_stack(void);
//void        init_data(t_data_push *data);

// TESTS
t_min_data  *new_min_data(int data);
void        add_back(t_min_data **mini, t_stack *a, int data);
t_min_data  *parse_next_mins(t_stack *a, int how_many);
void        collect_on_way(t_stack *a, t_stack *b, int how_many, t_min_data *mins);
// exSolver
//int     is_empty(t_stack *b);
//int     is_sorted(t_stack *a);
//int     is_rev_sorted(t_stack *b);
//int     guit_recursive(int data, int count, t_node *current_node);
//void    solver(t_stack *a, t_stack *b);

// Solver
void    solver(t_stack *a, t_stack *b);
void    solver_short(t_stack *a);
void    solver_med(t_stack *a, t_stack *b);
void    solver_long(t_stack *a, t_stack *b);

// Solver utils
int     is_sorted(t_stack *a);
int     is_rev_sorted(t_stack *b);
int     is_empty(t_stack *b);
int     get_min_data(t_node *node);
int     get_max_data(t_node *node);

// Solver utils 2
int     get_median_data(t_stack *stack, int median, int max, int nb_loop);
void    move_to(t_stack *a, t_stack *b, int median);
int     guit_recursive(int data, int count, t_node *current_node);
void    sort_b(t_stack *b, t_stack *a);

// Solver utils 3
int     get_pos_data(t_node *node, int min_data);
int     get_next_min_data(t_node *node, int min_data);
int     get_how_many_data(t_min_data *min, int dir, int loop, int stack_half);

// Solver long utils
void    check_2_data(t_stack *a, t_stack *b);
void    check_x_data(t_stack *a, t_stack *b);

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
