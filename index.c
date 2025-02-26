#include "push_swap.h"

void first_index(t_stack **stack)
{
    t_stack *node = *stack;

    while (node)
    {
        node->index = -1;
        node = node->next;
    }
}

t_stack *get_min(t_stack **a)
{
    t_stack *node = *a;
    t_stack *min_node = NULL;

    while (node)
    {
        if (node->index == -1 && (!min_node || node->data < min_node->data))
            min_node = node;
        node = node->next;
    }
    return min_node;
}

void indexing(t_stack **stack)
{
    t_stack *temp;
    int size;
    int i = 0;

    if (!stack || !*stack)
        return;

    first_index(stack);
    size = ft_listsize(*stack);

    while (i < size)
    {
        temp = get_min(stack);
        if (temp)
        {
            temp->index = i;
        }   
        i++;
    }
}
