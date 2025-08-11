/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:51:09 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/11 17:54:47 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	i = 1;
	while (i < argc)
	{
		check_arg(argv[i], argc);
		i++;
	}
	stack_a = parse_arg(argc, argv);
	check_sorted(&stack_a);
	stack_b = NULL;
	execute_sort(&stack_a, &stack_b, ft_listsize(stack_a));
	return (0);
}
