#include "push_swap.h"

int max_bits(t_stack **stack_a)
{
    t_stack *node = *stack_a;
    int max = node->index;
    int max_bits = 0;

    while (node)
    {
        if (node->index > max)
            max = node->index;
        node = node->next;
    }

    while ((max >> max_bits) != 0)
        max_bits++;

    return max_bits;
}

void radix(t_stack **stack_a, t_stack **stack_b)
{
    int size = ft_listsize(*stack_a);
    int max_bit = max_bits(stack_a);
    int i = 0;
    int j=0;
    t_stack *node;

    while (i < max_bit)
    {
        j = 0;
        while (j < size)
        {
            node = *stack_a;
            if (((node->index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        while (*stack_b)
            pa(stack_a, stack_b);
        i++;
    }
}