/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:35:34 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/28 14:13:52 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isduplicate(t_node *head, int value)
{
	t_node	*current;

	current = head;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_isvalid(int str)
{
	while (str)
	{
		if (ft_isascii(str) == 0)
			return (0);
		if (ft_isdigit == 0)
		{
			error_not_number();
			return (0);
		}
		if (ft_isduplicate == 1)
		{
			error_duplicate();
			return (0);
		}
	}
	return (1)
}