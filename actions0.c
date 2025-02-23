#include "push_swap.h"

int ft_listsize(t_stack *lst)
{
    size_t i;
    i = 0;
    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}
