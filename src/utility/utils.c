/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:37:51 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/11 12:29:24 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
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

void	ft_list_remove(t_node *node)
{
	if (node)
		free(node);
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
