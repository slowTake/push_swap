/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:50:48 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/07 10:34:10 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(const char *str, int argc)
{
	int	i;

	i = 0;
	if (argc <= 1)
		error_and_exit();
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

t_node	*parse_arg(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*new_node;
	int		i;
	long	num;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			error_and_exit();
		if (ft_isduplicate(stack_a, (int)num))
			error_duplicate();
		new_node = ft_listnew((int)num);
		if (!new_node)
		{
			ft_putstr_fd("Error: Mem fail\n", 2);
			return (0);
		}
		ft_listadd_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}

void	execute_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	*sorted_stack;

	if (check_sorted(*stack_a))
		return ;
	sorted_stack = stack_to_array(stack_a, size);
	if (!sorted_stack)
		error_and_exit();
	bubble_sort(sorted_stack, size);
	normalize_stack(stack_a, sorted_stack, size);
	free(sorted_stack);
	// if (size <= 5)
	// 	sort_5();
	// else
	radix_sort(stack_a, stack_b);
}
