/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:51:09 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/07 10:20:41 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

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
	if (!stack_a || ft_listsize(stack_a) <= 1)
	{
		ft_clearlist(&stack_a);
		return (0);
	}
	if (check_sorted(stack_a))
	{
		ft_clearlist(&stack_a);
		return (0);
	}
	stack_b = NULL;
	execute_sort(&stack_a, &stack_b, ft_listsize(stack_a));
	ft_clearlist(&stack_b);
	ft_clearlist(&stack_a);
	return (0);
}
