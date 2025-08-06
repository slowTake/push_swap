/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:51:09 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/06 16:07:28 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		*sorted_stack;
	int		i;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (!check_arg(argv[i], argc))
			error_and_exit();
		i++;
	}
	stack_a = parse_arg(argc, argv);
	if (check_sorted(stack_a))
	{
		ft_clearlist(&stack_a);
		return (0);
	}
	size = ft_listsize(stack_a);
	if (size <= 1)
	{
		ft_clearlist(&stack_a);
		return (0);
	}
	sorted_stack = stack_to_array(&stack_a, ft_listsize(stack_a));
	if (!sorted_stack)
	{
		ft_clearlist(&stack_a);
		return (1);
	}
	bubble_sort(sorted_stack, ft_listsize(stack_a));
	normalize_stack(&stack_a, sorted_stack, ft_listsize(stack_a));
	radix_sort(&stack_a, &stack_b);
	free(sorted_stack);
	ft_clearlist(&stack_a);
	ft_clearlist(&stack_b);
}
