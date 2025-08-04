/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:51:09 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/04 09:50:56 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*tmp;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!check_arg(argv[i], argc))
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
		ft_printf("sorted!");
}
