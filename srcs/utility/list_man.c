/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:03:00 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/13 15:15:16 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_listnew(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_listadd_back(t_node **list, t_node *new_node)
{
	t_node	*current;

	if (!list || !new_node)
		return ;
	if (*list == NULL)
	{
		*list = new_node;
		return ;
	}
	current = *list;
	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
}

int	ft_listsize(t_node *list)
{
	int	count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

void	ft_clearlist(t_node **list)
{
	t_node	*current;
	t_node	*next;

	if (!list)
		return ;
	current = *list;
	while (current != NULL)
	{
		next = current->next;
		ft_list_remove(current);
		current = next;
	}
	*list = NULL;
}
