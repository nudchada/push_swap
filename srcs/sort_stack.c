/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:19:52 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/08 10:03:27 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_stack_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*max_node;

	max_node = find_max(*a);
	if (*a == max_node)
		ra(a);
	else if ((*a)->next == max_node)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	size_a;

	size_a = stack_size(*a);
	while (size_a > 3 && stack_size(*b) < 2 && !is_sorted(*a))
	{
		pb(a, b);
		size_a--;
	}
	while (size_a > 3 && !is_sorted(*a))
	{
		update_stack_a(*a, *b);
		push_a_to_b(a, b);
		size_a--;
	}
	sort_three(a);
	while (*b)
	{
		find_target_b(*a, *b);
		push_b_to_a(b, a);
	}
	min_on_top(a);
}
