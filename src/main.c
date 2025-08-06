/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:51:09 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/06 13:15:00 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	int		*sorted_stack;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!check_arg(argv[i], argc))
			error_and_exit();
		i++;
	}
	stack_a = parse_arg(argc, argv);
	sorted_stack = stack_to_array(&stack_a, ft_listsize(stack_a));
	bubble_sort(sorted_stack, ft_listsize(stack_a));
	normalize_stack(&stack_a, sorted_stack, ft_listsize(stack_a));
	free(sorted_stack);
	if (check_sorted(stack_a))
		ft_printf("sorted!");
	ft_clearlist(&stack_a);
}

// value tester and checker: while, tmp
// tmp = stack_a;
// while (tmp)
// {
// 	printf("%d\n", tmp->value);
// 	tmp = tmp->next;
// }