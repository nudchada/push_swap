/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:05:27 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/08 10:30:48 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// find closest smaller number
static void	find_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_b;
	t_stack_node	*target;
	int				curr_target;

	while (a)
	{
		curr_target = INT_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->content < a->content && curr_b->content >= curr_target)
			{
				curr_target = curr_b->content;
				target = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (curr_target == INT_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

// operations to bring a node on top + operations to bring a->target on top
static void	find_push_cost(t_stack_node *a, t_stack_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		if (a->above_median)
			a->push_cost = a->index;
		else
			a->push_cost = size_a - a->index;
		if (a->target->above_median)
			a->push_cost += a->target->index;
		else
			a->push_cost += size_b - (a->target->index);
		a = a->next;
	}
}

t_stack_node	*find_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	long			cheapest_cost;

	if (!stack)
		return (NULL);
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		stack->cheapest = false;
		if (stack->push_cost < cheapest_cost)
		{
			cheapest_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
	return (cheapest_node);
}

void	update_stack_a(t_stack_node *a, t_stack_node *b)
{
	find_target_a(a, b);
	find_push_cost(a, b);
	find_cheapest(a);
}
