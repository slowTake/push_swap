/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:55:52 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/31 10:38:40 by pnurmi           ###   ########.fr       */
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
t_node				*parse_arg(char *argv);
long				ft_atol(const char *str);

// list man
void				ft_clearlist(t_node **stack);
void				ft_listadd_back(t_node **stack, t_node *new);
t_node				*ft_listnew(int value);

// checks & errors
bool				ft_isduplicate(t_node *head, int value);
bool				ft_isvalid(int str);
int					is_int_overflow(const char *str);
void				error_not_number(void);
void				error_duplicate(void);
void				error_and_exit(void);

#endif