/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:19:12 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/08 11:34:11 by pnurmi           ###   ########.fr       */
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

int	*stack_to_array(t_node **stack_a, int size)
{
	int		*array;
	t_node	*current;
	int		i;

	i = 0;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	current = *stack_a;
	while (i < size)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	return (array);
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

int	find_smallest(t_node *stack_a)
{
	int	smallest_index;

	if (!stack_a)
		return (0);
	smallest_index = stack_a->index;
	while (stack_a)
	{
		if (stack_a->index < smallest_index)
			smallest_index = stack_a->index;
		stack_a = stack_a->next;
	}
	return (smallest_index);
}

int	find_where_smallest(t_node *stack_a)
{
	int	smallest_value;
	int	smallest_pos;
	int	current;

	if (!stack_a)
		return (-1);
	smallest_value = stack_a->index;
	smallest_pos = 0;
	current = 0;
	while (stack_a)
	{
		if (stack_a->index < smallest_value)
		{
			smallest_value = stack_a->index;
			smallest_pos = current;
		}
		stack_a = stack_a->next;
		current++;
	}
	return (smallest_pos);
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
