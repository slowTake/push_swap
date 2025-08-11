/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:13:49 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/11 16:38:01 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_duplicate(void)
{
	ft_putstr_fd("No duplicates please", 2);
	exit(EXIT_FAILURE);
}

void	error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	error_sorted(void)
{
	exit(EXIT_FAILURE);
}