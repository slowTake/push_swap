/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:50:48 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/31 09:42:02 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parse(char *str)
{
	int	i;

	i = 0;
	if (ft_isvalid(ft_atoi(str[i])) == 0)
	{
		ft_prinf("Please enter a valid input");
		ft_clearlist(*str);
	}
}

t_node	*parse_arg(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
	i = 0;
	if (argc >= 2)
	{
		while (ft_isdigt(argv[1]) == 1 && ft_duplicate(argv[1] == false))
		{
			ft_listadd_back(&stack_a, ft_listnew(argv[1][i]));
			if (!stack_a)
			{
				ft_putstr_fd("Error: Mem fail\n", 2);
				return (NULL);
			}
			i++;
		}
		return (stack_a);
	}
	else
		error_and_exit();
}

// if (argc == 2)
// {
// 	array = ft_split(argv[1], " ");
// 	if (!ft_isvalid())
// 		ft_clearlist(&stack_a);
// }
