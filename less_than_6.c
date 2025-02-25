/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:55:43 by seerel            #+#    #+#             */
/*   Updated: 2025/02/25 14:53:38 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void arg_2(t_stack **stack_a)
{
    if ((*stack_a)->data > (*stack_a)->next->data)
    {
        sa(stack_a);
    }
}

t_stack *min_node(t_stack *a)
{
    t_stack *node = a;
    t_stack *min_node = a;

    while (node)
    {
        if (node->data < min_node->data)
            min_node = node;
        node = node->next;
    }
    return min_node;
}

void arg_3(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min = min_node(*stack_a);
    while ((*stack_a)->data != min->data)
        ra(stack_a);

    pb(stack_a, stack_b);

    arg_2(stack_a);

    pa(stack_a, stack_b);
}

void arg_4(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min = min_node(*stack_a);
    while ((*stack_a)->data != min->data)
        ra(stack_a);

    pb(stack_a, stack_b);

    arg_3(stack_a,stack_b);

    pa(stack_a, stack_b);
}

void arg_5(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *min = min_node(*stack_a);
    while ((*stack_a)->data != min->data)
        ra(stack_a);

    pb(stack_a, stack_b);

    arg_4(stack_a,stack_b);

    pa(stack_a, stack_b);
}




#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_stack *new_node(int data)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

void print_stack(t_stack *stack, char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d -> ", stack->data);
        stack = stack->next;
    }
    printf("NULL\n");
}

void append_node(t_stack **stack, int data)
{
    t_stack *new = new_node(data);
    if (!new)
        return;

    if (!*stack)
    {
        *stack = new;
        return;
    }

    t_stack *temp = *stack;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

int main()
{
    t_stack *stack_a = NULL;
    append_node(&stack_a, 2);
    append_node(&stack_a, 1);
    append_node(&stack_a, 3);
    append_node(&stack_a, 6);
    append_node(&stack_a, 5);

    t_stack *stack_b = NULL;

    // printf("Başlangıç:\n");
    // print_stack(stack_a, "Stack A");
    // print_stack(stack_b, "Stack B");

    // printf("\n*** 3 Eleman için Sıralama (arg_3) ***\n");
    // arg_3(&stack_a, &stack_b);
    // print_stack(stack_a, "Stack A");
    // print_stack(stack_b, "Stack B");

    printf("\n*** 5 Eleman için Sıralama (arg_4) ***\n");
    arg_5(&stack_a, &stack_b);
    print_stack(stack_a, "Stack A");
    print_stack(stack_b, "Stack B");

    return 0;
}



