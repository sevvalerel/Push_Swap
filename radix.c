/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:39:55 by seerel            #+#    #+#             */
/*   Updated: 2025/02/23 21:21:09 by seerel           ###   ########.fr       */
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
	t_stack	*current;
	t_stack	*min_node;
	int		min_val;
    current = *a;
	min_val =current->data;
	min_node = NULL;
	
	while (current)
	{
		if (current->index == -1 && current->data < min_val)
		{
			min_val = current->data;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}


void index(t_stack **stack)
{
    t_stack *node;
    t_stack *temp;
    temp=*stack;
    node = *stack;
    int size=ft_listsize(*stack);
    int a=0;

    while (a<size)
    {
        if (node->index == -1)
        {
            temp=get_min(stack);
            temp->index=a;
            a++;
        }
        size--;
    }
}

t_stack *create_node(int data) {
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    new_node->data = data;
    new_node->index = -1;  // Başlangıçta index -1
    new_node->next = NULL;
    return new_node;
}
#include <stdio.h>
#include <stdlib.h>
// main fonksiyonu
int main() {
    // Bağlı listeyi oluşturma
    t_stack *stack = create_node(10);    // node1: data = 10
    stack->next = create_node(5);        // node2: data = 5
    stack->next->next = create_node(8);  // node3: data = 8
    stack->next->next->next = create_node(3);  // node4: data = 3

    // first_index fonksiyonunu çağırma (tüm index'leri -1 yap)
    first_index(&stack);

    // index fonksiyonunu çağırma (index değerlerini güncelle)
    index(&stack);

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