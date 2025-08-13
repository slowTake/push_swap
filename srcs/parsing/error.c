/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:13:49 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/13 14:41:58 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_duplicate(t_node **stack)
{
	ft_putstr_fd("Error\n", 2);
	ft_clearlist(stack);
	exit(EXIT_FAILURE);
}

void	error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	error_overflow(t_node **stack)
{
	ft_putstr_fd("Error\n", 2);
	ft_clearlist(stack);
	exit(EXIT_FAILURE);
}
