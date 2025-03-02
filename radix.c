/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:21:10 by seerel            #+#    #+#             */
/*   Updated: 2025/03/02 13:04:29 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(t_stack **stack_a)
{
	t_stack	*node;
	int		max;
	int		max_bits;

	node = *stack_a;
	max = node->index;
	max_bits = 0;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		max_bit;
	int		i;
	int		j;
	t_stack	*node;

	size = ft_listsize(*stack_a);
	max_bit = max_bits(stack_a);
	i = 0;
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
