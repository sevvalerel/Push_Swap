/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:31:13 by seerel            #+#    #+#             */
/*   Updated: 2025/03/03 10:46:17 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	node = *stack;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}

void	free_split(char **list)
{
	size_t	i;

	if (!list)
		return ;
	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}
