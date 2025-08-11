/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:19:12 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/11 12:29:16 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *array, int size)
{
	int	temp;
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	normalize_stack(t_node **stack, int *sorted_array, int size)
{
	t_node	*current;
	int		i;

	current = *stack;
	while (current != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == sorted_array[i])
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	smallest;

	while (ft_listsize(*stack_a) > 3)
	{
		smallest = find_where_smallest(*stack_a);
		if (smallest <= ft_listsize(*stack_a) / 2)
		{
			while (smallest-- > 0)
				move_ra(stack_a);
		}
		else
		{
			while (smallest++ < ft_listsize(*stack_a))
				move_rra(stack_a);
		}
		move_pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (*stack_b)
		move_pa(stack_a, stack_b);
}

void	sort_3(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a < b && b > c && a < c)
	{
		move_sa(stack_a);
		move_ra(stack_a);
	}
	else if (a > b && b < c && a < c)
		move_sa(stack_a);
	else if (a < b && b > c && a > c)
		move_rra(stack_a);
	else if (a > b && b > c && a > c)
	{
		move_sa(stack_a);
		move_rra(stack_a);
	}
	else if (a > b && b < c && a > c)
	{
		move_ra(stack_a);
	}
}

void	sort_2(t_node **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		move_sa(stack_a);
}
