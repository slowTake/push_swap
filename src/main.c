/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:51:09 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/28 12:36:45 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted;

int	main(int argc, char *argv[])
{
	char	*test;

	test = argv[1];
	if (argc == 2)
	{
		printf("%s \n", argv[1]);
		ft_printf("ft_printf");
	}
}
// parsing
// check if input makes sense
// check if digit
// if duplicate
// signed ints
// if something other than number error message
// if numbers then check if already sorted