#include "push_swap.h"

int ft_listsize(t_struct *lst)
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

static void swap(t_struct **node)
{
    int temp;

    if (ft_listsize(*node) > 1)
    {
        temp = (*node)->data;
        (*node)->data = (*node)->next->data;
        (*node)->next->data = temp;
    }
    return;
}