/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:35:34 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/30 15:37:48 by pnurmi           ###   ########.fr       */
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

bool	ft_isvalid(int str)
{
	while (str)
	{
		if (ft_isdigit == 0)
		{
			error_not_number();
			return (false);
		}
		if (ft_isduplicate == true)
		{
			error_duplicate();
			return (false);
		}
	}
	return (true);
}
