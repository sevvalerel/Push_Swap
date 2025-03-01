#include "push_swap.h"

int error()
{
    write(1, "error\n", 6);
    exit(1);
}
#include <stdio.h>
void sorting(t_stack **stack_a, t_stack **stack_b, char **str)
{
    int len=0;
    int i = 0;
    while (str[i])
    {
        ft_addback(stack_a, str[i]);
        i++;
    }
    len=ft_listsize(*stack_a);
    indexing(stack_a);
    if(len==2)
        arg_2(stack_a);
    else if(len==3)
        arg_3(stack_a ,stack_b);
    else if(len==4)
        arg_4(stack_a ,stack_b);
    else if(len==5)
        arg_5(stack_a ,stack_b);       
    else
        radix(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
}

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    char **str;

    if (argc == 1)
        return 0;

    if (argc == 2)
    {
        str = ft_split(argv[1], ' ');
        free_split(str);
    } 

    else
        str = argv + 1;

    if (str == NULL)
        error();
    if(check_sorted(&stack_a))
    {
        free_stack(&stack_a);
        free_stack(&stack_b);
        return 0;
    }
    if (!check_num(str) || !repeat(str) ||!check_long(str))
        error();
    sorting(&stack_a, &stack_b, str);
    return 0;
}
