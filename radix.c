/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:39:55 by seerel            #+#    #+#             */
/*   Updated: 2025/02/24 16:14:30 by seerel           ###   ########.fr       */
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
        a++;
    }
}

t_stack *create_node(int data) {
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return NULL;
    
    new_node->data = data;
    new_node->index = -1;
    new_node->next = NULL;
    return new_node;
}

#include <stdio.h>
#include <stdlib.h>
int main() {
    // Bağlı listeyi oluşturma
    t_stack *stack = create_node(10);
    if (!stack) return 1; // malloc başarısızsa çık
    
    stack->next = create_node(5);
    if (!stack->next) return 1;
    
    stack->next->next = create_node(8);
    if (!stack->next->next) return 1;
    
    stack->next->next->next = create_node(3);
    if (!stack->next->next->next) return 1;

    // first_index fonksiyonunu çağırma
    first_index(&stack);

    // index fonksiyonunu çağırma
    indexing(&stack);

    // Sonuçları yazdırma
    t_stack *node = stack;
    while (node) {
        printf("Node data: %d, index: %d\n", node->data, node->index);
        node = node->next;
    }

    // Bellek temizleme
    t_stack *temp;
    while (stack) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
}
