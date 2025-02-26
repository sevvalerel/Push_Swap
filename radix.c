/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:05:10 by seerel            #+#    #+#             */
/*   Updated: 2025/02/26 15:26:30 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max_bits(t_stack **stack_a)
{
    t_stack *node;
    int max;
    int max_bits;

    max_bits = 0;
    node = *stack_a;
    max = node->index;

    while (node)
    {
        if (node->index > max)
            max = node->index;
        node=node->next;
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void radix(t_stack **stack_a, t_stack **stack_b)
{
    int size;
    int max_bit;
    int i = 0;
    int j;
    t_stack *node;

    size = ft_listsize(*stack_a);
    max_bit = max_bits(stack_a);

    while (i < max_bit)
    {
        j = 0;
        while (j < size)
        {
            node = *stack_a; // güncel stack_a yı almalı
            if (((node->index >> i) & 1) == 1)
                ra(stack_a);
            else
                pb(stack_a, stack_b);
            j++;
        }
        while (*stack_b)
            pa(stack_b, stack_a);
        i++;
    }
}
