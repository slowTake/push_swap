/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:37:46 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/11 12:35:38 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rrotate(t_node **stack)
{
	t_node	*last;
	t_node	*sec_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	sec_last = last->prev;
	sec_last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev = NULL;
}

void	move_rra(t_node **stack_a)
{
	move_rrotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	move_rrb(t_node **stack_b)
{
	move_rrotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	move_rrr(t_node **stack_a, t_node **stack_b)
{
	move_rrotate(stack_a);
	move_rrotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
