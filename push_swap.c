#include "push_swap.h"

int error()
{
    write(1,"error\n",6);
    exit(0);
}
#include <stdio.h>
int main(int argc, char **argv)
{
    t_stack **stack_a;
    t_stack **stack_b;
    char **str;
    int i = -1;

    if (argc == 1)
        return 0;

    if (argc == 2)
    {
        str = ft_split(argv[1], ' ');
    }
    else
    {
        i = 0;
        str = argv;
    }
    if(str==NULL)
        error();
    while(str[++i])
    {
        if(!check_num(str)&&!repeat(str)&&check_sorted(str)&&check_long(str))
            error();
    }

    stack_a=(t_stack **)malloc(sizeof(t_stack));
    stack_b=(t_stack **)malloc(sizeof(t_stack));
    if(stack_a == NULL || stack_b== NULL )
    {
        free(stack_a);
        free(stack_b);
        error();// gerek var mı?
    }
    stack_a=NULL;
    stack_b=NULL;
    i=0;
    while(str[i])
    {
        ft_addback(stack_a,str[i]);
        i++;
    }
    while(*stack_a)
    {
        printf("%d",(*stack_a)->data);
        *stack_a=(*stack_a)->next;
    }


}
