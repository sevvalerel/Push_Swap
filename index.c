/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:39:55 by seerel            #+#    #+#             */
/*   Updated: 2025/02/26 15:27:19 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void first_index(t_stack **stack)
{
    t_stack *node;
    node = *stack;

    while (node)
    {
        node->index = -1;
        node = node->next;
    }
}

void *get_min(t_stack **a)
{
    t_stack *node;
    t_stack *min_node;

    if (!a || !*a)  
        return NULL;

    node = *a;
    min_node = NULL;

    while (node)
    {
        if (node->index == -1 && (!min_node || node->data < min_node->data))
        {
            min_node = node;
        }
        node = node->next;
    }
    return min_node;
}


void indexing(t_stack **stack)
{
    t_stack *node;
    t_stack *temp;
    temp = *stack;
    node = *stack;
    if (!stack || !*stack)
        return;
    int size = ft_listsize(*stack);
    int a = 0;

    while (a < size)
    {
        if (node->index == -1)
        {
            temp = get_min(stack);
            temp->index = a;
        }
        node = node->next;
        a++;
    }
}