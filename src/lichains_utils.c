#include "push_swap.h"

void	lstadd_back(t_stack **alst, t_stack *new)
{
        t_stack	*tmp;

        if (*alst)
        {
                tmp = lstlast(*alst);
                tmp->next = new;
        }
        else
                *alst = new;
}

void    lstadd_front(t_stack **alst, t_stack *new)
{
        if (!alst || !new)
                return ;
        new->next = *alst;
        *alst = new;
}

t_stack  *lstnew(int content)
{
        t_stack  *cell;

        cell = malloc(sizeof(t_stack));
        if (!cell)
                return (NULL);
        cell->nb = content;
        cell->next = NULL;
        return (cell);
}

t_stack  *lstlast(t_stack *lst)
{
		if (!lst)
                return (NULL);
        while (lst)
        {
                if (lst->next == NULL)
                        return (lst);
                lst = lst->next;
        }
        return (lst);
}

int     lstsize(t_stack *lst)
{
        int     count;

        count = 0;
        while (lst)
        {
                lst = lst->next;
                count++;
        }
        return (count);
}
