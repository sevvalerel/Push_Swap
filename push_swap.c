#include "push_swap.h"

int error()
{
    write(1, "error\n", 6);
    exit(1);
}

void sorting(t_stack *stack_a, t_stack *stack_b, char **str)
{
    int i = 0;
    while (str[++i])
        ft_addback(&stack_a,str[i]);
    indexing(&stack_a);
    radix(&stack_a, &stack_b);
    //free_stack(&stack_a);
    //free_stack(&stack_b);
}

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;
    char **str;
    if (argc == 1)
        return 0;

    if (argc == 2)
        str = ft_split(argv[1], ' ');
    else
        str = argv;
    if (str == NULL)
        error();
    if (!check_num(str) || !repeat(str) || check_sorted(str) || !check_long(str))
        error();
    sorting(stack_a, stack_b, str);
    return 0;
}
