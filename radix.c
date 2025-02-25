/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:05:10 by seerel            #+#    #+#             */
/*   Updated: 2025/02/25 15:58:22 by seerel           ###   ########.fr       */
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
    }
    while ((max >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void radix(t_stack **stcak_a, t_stack **stcak_b)
{
    int size;
    int max_bit;
    int i;
    int j;
    t_stack *node;

    size = ft_listsize(*stcak_a);
    max_bit=max_bits(stcak_a);
    
    while(i<max_bit)
    {
        j=0;
        while(j<size)
        {
            (node->data>>i &1)==1;
        }
    }
    
}
