/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:55:43 by seerel            #+#    #+#             */
/*   Updated: 2025/02/26 17:56:40 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void arg_2(t_stack **stack_a)
{
    if ((*stack_a)->data > (*stack_a)->next->data)
    {
        sa(stack_a);
    }
}

t_stack *min_node(t_stack *a)
{
    t_stack *node = a;
    t_stack *min_node = a;

    while (node)
    {
        if (node->data < min_node->data)
            min_node = node;
        node = node->next;
    }
    return min_node;
}

void arg_3(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min = min_node(*stack_a);
    while ((*stack_a)->data != min->data)
        ra(stack_a);

    pb(stack_a, stack_b);

    arg_2(stack_a);

    pa(stack_a, stack_b);
}

void arg_4(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min = min_node(*stack_a);
    while ((*stack_a)->data != min->data)
        ra(stack_a);

    pb(stack_a, stack_b);

    arg_3(stack_a,stack_b);

    pa(stack_a, stack_b);
}

void arg_5(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min = min_node(*stack_a);
    while ((*stack_a)->data != min->data)
        ra(stack_a);

    pb(stack_a, stack_b);

    arg_4(stack_a,stack_b);

    pa(stack_a, stack_b);
}
