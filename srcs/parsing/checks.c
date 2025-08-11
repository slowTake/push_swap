/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:35:34 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/11 17:12:34 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_isduplicate(t_node *head, int value)
{
	t_node	*current;

	current = head;
	while (current)
	{
		if (current->value == value)
			return (true);
		current = current->next;
	}
	return (false);
}

int	is_int_overflow(const char *str)
{
	long	val;

	val = ft_atol(str);
	if (val < INT_MIN || val > INT_MAX)
	{
		ft_putstr_fd("ERROR: Int overflow \n", 2);
		exit(EXIT_FAILURE);
	}
	return (1);
}

int	check_sorted(t_node **stack)
{
	t_node	*current;

	if (!stack || ft_listsize(*stack) <= 1)
	{
		ft_clearlist(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	ft_clearlist(stack);
	exit(EXIT_FAILURE);
}
