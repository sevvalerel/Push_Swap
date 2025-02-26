/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:31:13 by seerel            #+#    #+#             */
/*   Updated: 2025/02/26 17:44:10 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void free_stack(t_stack **stack)
{
    t_stack *node;
    t_stack *temp;

    if (!stack || !*stack)
        return;

    node = *stack;
    while (node)
    {
        temp = node;
        node = node->next;
        free(temp);
    }
}
