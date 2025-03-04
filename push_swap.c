/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerel <seerel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:20:51 by seerel            #+#    #+#             */
/*   Updated: 2025/03/03 10:49:24 by seerel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

static void	sorting(t_stack **stack_a, t_stack **stack_b, char **str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		ft_addback(stack_a, str[i]);
		i++;
	}
	len = ft_listsize(*stack_a);
	indexing(stack_a);
	if (len == 2)
		arg_2(stack_a);
	else if (len == 3)
		arg_3(stack_a);
	else if (len == 4)
		arg_4(stack_a, stack_b);
	else if (len == 5)
		arg_5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}

static int	check_arguments(char **str, int is_split_used)
{
	if (!str)
		return (0);
	if (check_sorted(str))
	{
		if (is_split_used)
			free_split(str);
		return (0);
	}
	if (!check_num(str) || !repeat(str) || !check_long(str))
	{
		if (is_split_used)
			free_split(str);
		error();
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;
	int		is_split_used;

	stack_a = NULL;
	stack_b = NULL;
	is_split_used = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		is_split_used = 1;
	}
	else
		str = argv + 1;
	if (!check_arguments(str, is_split_used))
		return (0);
	sorting(&stack_a, &stack_b, str);
	if (is_split_used)
		free_split(str);
	return (0);
}
