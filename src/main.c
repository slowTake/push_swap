/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:51:09 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/31 13:56:40 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*tmp;
	int		i;

	if (argc <= 1)
		error_and_exit();
	i = 1;
	while (i < argc)
	{
		printf("Checking arg: '%s'\n", argv[i]);
		if (!check_arg(argv[i]))
			error_and_exit();
		i++;
	}
	stack_a = parse_arg(argc, argv);
	tmp = stack_a;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	if (check_sorted(stack_a))
	{
		// already sorted
	}
}
// parsing
// check if input makes sense
// check if digit
// if duplicate
// signed ints
// if something other than number error message
// if numbers then check if already sorted
