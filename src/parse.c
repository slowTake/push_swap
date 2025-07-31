/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:50:48 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/31 11:25:52 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] && str[i] != ' ')
			return (0);
	}
	return (1);
}

t_node	*parse_arg(int argc, char **argv)
{
	t_node	*stack_a;
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
		ft_listadd_back(&stack_a, ft_listnew((int)num));
		if (!stack_a)
		{
			ft_putstr_fd("Error: Mem fail\n", 2);
			return (NULL);
		}
		i++;
	}
	return (stack_a);
}
