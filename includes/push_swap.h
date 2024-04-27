/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:03:47 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/08 10:58:12 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h> 
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"

typedef struct s_stack_node
{
	int					content;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	struct s_stack_node	*target;
}	t_stack_node;

//stack initiation
void			free_array(char **array);
void			free_stack(t_stack_node **stack);
void			handle_errors(t_stack_node **a);
void			init_stack(t_stack_node **a, char **argv);

//stack utils
int				stack_size(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

//operations
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **b, t_stack_node **a);
void			pb(t_stack_node **a, t_stack_node **b);

//algorithms
void			sort_three(t_stack_node **a);
void			sort_stack(t_stack_node **a, t_stack_node **b);
void			update_index(t_stack_node *stack);
t_stack_node	*find_cheapest(t_stack_node *stack);
void			update_stack_a(t_stack_node *a, t_stack_node *b);
void			push_a_to_b(t_stack_node **a, t_stack_node **b);
void			find_target_b(t_stack_node *a, t_stack_node *b);
void			push_b_to_a(t_stack_node **b, t_stack_node **a);
void			min_on_top(t_stack_node **a);

#endif