/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:37:46 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/01 11:38:22 by pnurmi           ###   ########.fr       */
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
	ft_putstr_fd("sa\n", 1);
}

void	move_sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_b = second;
	ft_putstr_fd("sb\n", 1);
}

void	move_ss(t_node **stack_a, t_node **stack_b)
{
	move_sa(stack_a);
	move_sb(stack_b);
	ft_putstr_fd("ss\n", 1);
}

void	move_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*first_a;
	t_node	*first_b;

	if (!stack_b || !*stack_b)
		return ;
	first_a = *stack_a;
	first_b = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	first_b->prev = NULL;
	if (*stack_a)
		(*stack_a)->prev = first_b;
	first_a->prev = first_b;
	first_b->next = first_a;
	*stack_a = first_b;
	ft_putstr_fd("pa\n", 1);
}

void	move_pb(t_node stack_a, t_node stack_b);
void	move_ra(t_node stack_a, t_node stack_b);
void	move_rb(t_node stack_a, t_node stack_b);
void	move_rr(t_node stack_a, t_node stack_b);
void	move_rra(t_node stack_a, t_node stack_b);
void	move_rrb(t_node stack_a, t_node stack_b);
void	move_rrr(t_node stack_a, t_node stack_b);
