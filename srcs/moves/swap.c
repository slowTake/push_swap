/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:31:46 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/11 12:31:51 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	move_sa(t_node **stack_a)
{
	move_swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	move_sb(t_node **stack_b)
{
	move_swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	move_ss(t_node **stack_a, t_node **stack_b)
{
	move_swap(stack_a);
	move_swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
