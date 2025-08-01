/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:37:46 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/01 09:51:39 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_a = second;
}

void	move_sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
}
void	move_ss(t_node stack_a, t_node stack_b);
void	move_pa(t_node stack_a, t_node stack_b);
void	move_pb(t_node stack_a, t_node stack_b);
void	move_ra(t_node stack_a, t_node stack_b);
void	move_rb(t_node stack_a, t_node stack_b);
void	move_rr(t_node stack_a, t_node stack_b);
void	move_rra(t_node stack_a, t_node stack_b);
void	move_rrb(t_node stack_a, t_node stack_b);
void	move_rrr(t_node stack_a, t_node stack_b);
