#include "push_swap.h"

void swap(t_stack**node)
{
    int temp;

    if (!node || !*node || !(*node)->next)
        return;

    if (ft_listsize(*node) > 1)
    {
        temp = (*node)->data;
        (*node)->data = (*node)->next->data;
        (*node)->next->data = temp;
    }
    return;
}

void sa(t_stack **stack_a)
{
    swap(stack_a);
    write(1,"sa\n",3);
}

void sb(t_stack **stack_b)
{
    swap(stack_b);
    write(1,"sb\n",3);
}

void ss(t_stack **stack_a,t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1,"ss\n",3);
}

