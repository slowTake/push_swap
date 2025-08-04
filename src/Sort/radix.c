/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:19:41 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/04 16:32:29 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_all_b_to_a(t_node **stack_a, t_node **stack_b)
{
	while (ft_listsize(stack_b) != 0)
	{
		pa(stack_b, stack_a);
	}
}

void	stack_b_next_bit(t_node **stack_a, t_node **stack_b, int next_bit,
		int bit_count)
{
	int	size;

	size = ft_listsize(stack_b);
	while (size > 0 && next_bit <= bit_count)
	{
		if ((((*stack_b)->value >> next_bit) & 1) == 0)
			rb(stack_b);
		else
			pa(stack_a);
		size--;
	}
}
