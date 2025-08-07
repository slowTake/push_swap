/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:19:41 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/07 13:16:02 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all_to_a(t_node **stack_a, t_node **stack_b)
{
	while (ft_listsize(*stack_b) != 0)
	{
		move_pa(stack_a, stack_b);
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
	while (size > 0)
	{
		if ((((*stack_a)->value >> bit) & 1) == 1)
			move_pb(stack_a, stack_b);
		else
			move_ra(stack_a);
		size--;
	}
}

int	ft_max_bit(t_node *stack_a)
{
	int	max_bit;
	int	stack_size;

	max_bit = 0;
	stack_size = ft_listsize(stack_a);
	while ((1 << max_bit) < stack_size)
		max_bit++;
	return (max_bit);
}

void	radix_logic(t_node **stack_a, t_node **stack_b)
{
	int	max_bit;
	int	bit_pos;
	int	size;
	int	i;

	bit_pos = 0;
	max_bit = ft_max_bit(*stack_a);
	while (bit_pos < max_bit)
	{
		size = ft_listsize(*stack_a);
		i = 0;
		while (i < size)
		{
			if ((((*stack_a)->index >> bit_pos) & 1) == 1)
				move_pb(stack_a, stack_b);
			else
				move_ra(stack_a);
			i++;
		}
		while (ft_listsize(*stack_b) > 0)
			move_pa(stack_a, stack_b);
		bit_pos++;
	}
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	*array;

	size = ft_listsize(*stack_a);
	array = stack_to_array(stack_a, size);
	if (!array)
		return ;
	bubble_sort(array, size);
	normalize_stack(stack_a, array, size);
	free(array);
	radix_logic(stack_a, stack_b);
}
