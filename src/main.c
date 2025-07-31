/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:51:09 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/31 11:24:50 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;

	if (argc < 2)
		error_and_exit();
	check_arg(*argv);
	stack_a = parse_arg(argc, argv);
	if (check_sorted(stack_a))
	{
		//
		// error_and_exit;
	}
}
// parsing
// check if input makes sense
// check if digit
// if duplicate
// signed ints
// if something other than number error message
// if numbers then check if already sorted
