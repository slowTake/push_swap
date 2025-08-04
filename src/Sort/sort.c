/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:19:12 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/04 17:30:44 by pnurmi           ###   ########.fr       */
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
		j = i;
		while (j < size - 1)
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

int	*stack_array(t_node **stack_a, int size)
{
	int		*array;
	t_node	*current;
	int		i;

	i = 0;
	array = (int *)maloc(sizeof(int) * size);
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
	while (*stack != NULL)
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
