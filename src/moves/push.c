/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:33:04 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/11 12:33:06 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*first_b;

	if (!stack_b || !*stack_b)
		return ;
	first_b = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	first_b->prev = NULL;
	first_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = first_b;
	*stack_a = first_b;
	ft_putstr_fd("pa\n", 1);
}

void	move_pb(t_node **stack_a, t_node **stack_b)
{
	t_node *first_a;

	if (!stack_a || !*stack_a)
		return ;
	first_a = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	first_a->prev = NULL;
	first_a->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = first_a;
	*stack_b = first_a;
	ft_putstr_fd("pb\n", 1);
}