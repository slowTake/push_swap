/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:50:48 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/04 09:50:08 by pnurmi           ###   ########.fr       */
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
			return (NULL);
		}
		ft_listadd_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}
