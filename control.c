#include "push_swap.h"

#include <stdio.h>


int	check_num(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i] != NULL)
	{
		j = 0;

		if (str[i][j] == '-' || str[i][j] == '+')
			j++;

		if (str[i][j] == '\0')
			return 0;

		while (str[i][j] != '\0')
		{
			if (!ft_isdigit(str[i][j]))
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}


int repeat(char **str)
{
    int i = 0;
    int j = 0;
    while (str[i] != NULL)
    {
        j = i + 1;
        while (str[j])
        {
            if (ft_atoi(str[i]) == ft_atoi(str[j]))
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}

int	check_sorted(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	if (!node || !node->next)
		return (1);
	while (node->next)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}

int check_long(char **str)
{
    int i=0;
    while(str[i]!=NULL)
    {
        if(ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
             return 0;
        i++;
    }
    return 1;
}
