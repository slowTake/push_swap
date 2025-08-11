/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:51:09 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/11 16:46:20 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = parse_arg(argc, argv);
	if (!stack_check(&stack_a))
		error_and_exit();
	stack_b = NULL;
	execute_sort(&stack_a, &stack_b, ft_listsize(stack_a));
	return (0);
}
