/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:33:46 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/11 12:37:01 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	move_ra(t_node **stack_a)
{
	move_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	move_rb(t_node **stack_b)
{
	move_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	move_rr(t_node **stack_a, t_node **stack_b)
{
	move_rotate(stack_a);
	move_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
