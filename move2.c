#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*last;
	t_stack	*second_last;

	if (ft_listsize(*stack_a) > 1) 
	{
		second_last = *stack_a;
		while (second_last->next->next != NULL) 
			second_last = second_last->next;

		last = second_last->next; 
		second_last->next = NULL; 
		last->next = *stack_a; 
		*stack_a = last; 

		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b)
{
	t_stack	*last;
	t_stack	*second_last;

	if (ft_listsize(*stack_b) > 1) 
	{
		second_last = *stack_b;
		while (second_last->next->next != NULL) 
			second_last = second_last->next;

		last = second_last->next; 
		second_last->next = NULL; 
		last->next = *stack_b; 
		*stack_b = last; 

		write(1, "rrb\n", 4);
	}
}





