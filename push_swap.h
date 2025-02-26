#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    int data;
    int index;
    struct s_list *next;
} t_stack;

int ft_listsize(t_stack *lst);
t_stack *ft_lstlast(t_stack *lst);
void swap(t_stack **node);
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
int ft_isdigit(int x);
long ft_atoi(char *str);
int check_num(char **str);
int repeat(char **str);
int check_sorted(char **str);
int check_long(char **str);
char **ft_split(char *s, char c);
t_stack *ft_addback(t_stack **lst, char *node);
void free_stack(t_stack **stack);
void indexing(t_stack **stack);
void arg_2(t_stack **stack_a);
t_stack *min_node(t_stack *a);
void arg_3(t_stack **stack_a, t_stack **stack_b);
void arg_4(t_stack **stack_a, t_stack **stack_b);
void arg_5(t_stack **stack_a, t_stack **stack_b);
void radix(t_stack **stcak_a, t_stack **stcak_b);
int max_bits(t_stack **stack_a);
void sorting(t_stack **stack_a, t_stack **stack_b, char **str);


#endif