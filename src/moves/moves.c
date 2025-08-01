/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:37:46 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/01 14:48:15 by pnurmi           ###   ########.fr       */
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
	t_node	*first_a;

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