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

typedef struct  s_chunk
{
    int min;
    int max;
    int pos;
    int size;
}               t_chunk;

typedef struct  s_long
{
    int min;
    int max;
    int size;
    int high;
    int low;
    int by_front;
    int by_tail;
    int mult;
    int zone;
    int to_front;
}               t_long;

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

// List utils
void        display(t_stack *a, t_stack *b);
int         list_size(t_node *current_node);
t_node      *new_node(int data);
t_stack     *new_stack(void);

// List utils 2
void        chunk_init(t_chunk *c, t_stack *b);
void        long_init(t_long *data, t_stack *a, int nb_chunk);

// Solver
void    solver(t_stack *a, t_stack *b);
void    solver_short(t_stack *a);
void    solver_med(t_stack *a, t_stack *b);
void    solver_long(t_stack *a, t_stack *b, int nb_chunk);

// Solver utils
int     is_sorted(t_stack *a);
int     is_rev_sorted(t_stack *b);
int     is_empty(t_stack *b);
int     get_min_data(t_node *node);
int     get_max_data(t_node *node);

// Solver utils 2
int     get_median_data(t_stack *stack, int min_data, int max, int nb_loop);
void    move_to(t_stack *a, t_stack *b, int median);
int     guit_recursive(int data, int count, t_node *current_node);
void    sort_b(t_stack *b, t_stack *a);
int     get_by(t_node *node, int lower_bound, int higher_bound, int from);

// Solver utils 3
int     get_next_min_data(t_node *node, int min_data);
void    resolve_chunk(t_stack *a, t_stack *b);

// Solver utils 4
int     shortest_pos(t_node *node, int min, int max);

// Solver long
void    collect_long(t_stack *a, t_stack *b, t_long data);
void    set_median_low(t_long *data, t_stack *a, int nb_chunk);
int     smart_way_long(t_stack *a, t_long data, int *step);

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
