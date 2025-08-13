/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:55:52 by pnurmi            #+#    #+#             */
/*   Updated: 2025/08/13 14:42:40 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// parsing & util
int					ft_parse(char *str);
t_node				*parse_arg(int argc, char **argv);
long				ft_atol(const char *str, t_node **stack);
int					check_arg(const char *str, int argc);

// list man
t_node				*ft_listnew(int value);
void				ft_listadd_back(t_node **list, t_node *new_node);
void				ft_list_front(t_node **list, t_node *new_node);
int					ft_listsize(t_node *list);
void				ft_list_remove(t_node *node);
void				ft_clearlist(t_node **list);

// checks & errors
int					ft_isduplicate(t_node *head, int value);
bool				ft_isvalid(int str);
void				error_duplicate(t_node **stack);
void				error_and_exit(void);
int					check_sorted(t_node **stack);
void				error_overflow(t_node **stack);

// sort
void				bubble_sort(int *array, int size);
int					*stack_to_array(t_node **stack_a, int size);
void				normalize_stack(t_node **stack, int *sorted_array,
						int size);
void				all_to_a(t_node **stack_a, t_node **stack_b);
int					count_bit(int size);
int					execute_sort(t_node **stack_a, t_node **stack_b, int size);
void				sort_2(t_node **stack_a);
void				sort_3(t_node **stack_a);
void				sort_5(t_node **stack_a, t_node **stack_b);
int					find_where_smallest(t_node *stack_a);
int					find_smallest(t_node *stack_a);

// radix
int					ft_max_bit(t_node *stack_a);
int					find_max_index(t_node *stack_a);
void				radix_logic(t_node **stack_a, t_node **stack_b);
void				radix_sort(t_node **stack_a, t_node **stack_b);

// moves
void				move_swap(t_node **stack);
void				move_sa(t_node **stack_a);
void				move_sb(t_node **stack_b);
void				move_ss(t_node **stack_a, t_node **stack_b);
void				move_pa(t_node **stack_a, t_node **stack_b);
void				move_pb(t_node **stack_a, t_node **stack_b);
void				move_rotate(t_node **stack);
void				move_ra(t_node **stack_a);
void				move_rb(t_node **stack_b);
void				move_rr(t_node **stack_a, t_node **stack_b);
void				move_rrotate(t_node **stack);
void				move_rra(t_node **stack_a);
void				move_rrb(t_node **stack_b);
void				move_rrr(t_node **stack_a, t_node **stack_b);

#endif