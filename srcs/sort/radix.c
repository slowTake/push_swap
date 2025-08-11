/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:19:41 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/08 12:08:06 by pnurmi           ###   ########.fr       */
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

int	find_max_index(t_node *stack_a)
{
	int	max_index;

	max_index = 0;
	while (stack_a)
	{
		if (stack_a->index > max_index)
			max_index = stack_a->index;
		stack_a = stack_a->next;
	}
	return (max_index);
}

int	ft_max_bit(t_node *stack_a)
{
	int	max_bit;
	int	max_index;

	max_bit = 0;
	max_index = find_max_index(stack_a);
	while ((max_index >> max_bit) != 0)
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
