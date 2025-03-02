/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:20:31 by seerel            #+#    #+#             */
/*   Updated: 2025/03/02 13:01:31 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b != NULL)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
		write(1, "pa\n", 3);
	}
	return ;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a != NULL)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
		write(1, "pb\n", 3);
	}
	return ;
}

void	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_listsize(*stack_a) > 1)
	{
		first = *stack_a;
		last = ft_lstlast(*stack_a);
		*stack_a = (*stack_a)->next;
		last->next = first;
		first->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_listsize(*stack_b) > 1)
	{
		first = *stack_b;
		last = ft_lstlast(*stack_b);
		*stack_b = (*stack_b)->next;
		last->next = first;
		first->next = NULL;
		write(1, "rb\n", 3);
	}
}
