/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:19:08 by seerel            #+#    #+#             */
/*   Updated: 2025/03/02 12:55:03 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_index(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node)
	{
		node->index = -1;
		node = node->next;
	}
}

t_stack	*get_min(t_stack **a)
{
	t_stack	*node;
	t_stack	*min_node;

	node = *a;
	min_node = NULL;
	while (node)
	{
		if (node->index == -1 && (!min_node || node->data < min_node->data))
			min_node = node;
		node = node->next;
	}
	return (min_node);
}

void	indexing(t_stack **stack)
{
	t_stack	*temp;
	int		size;
	int		i;

	if (!stack || !*stack)
		return ;
	first_index(stack);
	size = ft_listsize(*stack);
	i = 0;
	while (i < size)
	{
		temp = get_min(stack);
		if (temp)
			temp->index = i;
		i++;
	}
}
