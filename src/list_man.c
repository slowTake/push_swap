/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:03:00 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/28 10:24:53 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_node **lst, t_node *new_node)
{
	t_node	*current;

	if (!lst || !new_node)
		return ;
	if (*lst)
	{
		*lst = new_node;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

void	ft_lst_front(t_node **lst, t_node *new_node)
{
	if (!lst || !new_node)
		return ;
	if (*lst)
		(*lst)->prev = new_node;
	new_node->next = *lst;
	*lst = new_node;
}

int	ft_lstsize(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_lst_remove(t_node *node)
{
	if (node)
		free(node);
}

void	ft_cleanlst(t_node **lst)
{
	t_node	*current;
	t_node	*temp;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		temp = current->next;
		ft_lst_remove(current);
		current = temp;
	}
	*lst = NULL;
}
