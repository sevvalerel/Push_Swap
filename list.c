/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:34:37 by seerel            #+#    #+#             */
/*   Updated: 2025/02/22 17:04:47 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_listsize(t_stack *lst)
{
    size_t i;
    i = 0;
    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}

t_stack *ft_lstlast(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

t_stack *ft_addback(t_stack **lst, char *node)
{
    t_stack *new_node;
    t_stack *last;
    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return NULL;
    
    new_node->data = ft_atoi(node);
    new_node->next = NULL;
    
    if (lst==NULL)
        *lst = new_node;
    else
    {
        last = ft_lstlast(*lst);
        last->next = new_node;
    }
    return new_node;
}