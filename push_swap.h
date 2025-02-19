#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>

typedef struct s_list
{
    int data;
    int index;
    struct s_list *next;
} t_struct;

#endif