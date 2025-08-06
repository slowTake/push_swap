/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:19:41 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/06 13:22:19 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_to_a(t_node **stack_a, t_node **stack_b)
{
	while (ft_listsize(*stack_b) != 0)
	{
		move_pa(stack_b, stack_a);
	}
}

void	stack_b_next_bit(t_node **stack_a, t_node **stack_b, int next_bit,
		int bit_count)
{
	int	size;

	size = ft_listsize(*stack_b);
	while (size > 0 && next_bit <= bit_count)
	{
		if ((((*stack_b)->value >> next_bit) & 1) == 0)
			move_rb(stack_b);
		else
			move_pa(stack_a, stack_b);
		size--;
	}
}

void	sort_stack_a_bits(t_node **stack_a, t_node **stack_b, int bit)
{
	int	size;

	size = ft_listsize(*stack_a);
	while (size > 0 && check_sorted(*stack_a) != true)
	{
		if ((((*stack_a)->value >> bit) & 1) == 1)
			move_pb(stack_a, stack_b);
		else
			move_ra(stack_a);
		size--;
	}
}

int	count_bit(int size)
{
	int	count;

	count = 0;
	while (size > 1)
	{
		size >>= 1;
		count++;
	}
	return (count);
}

void	radix(t_node **stack_a, t_node **stack_b);
// {
// int bit;
// int count;

// assig
// }