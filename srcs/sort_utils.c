/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:40:57 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/05 14:53:04 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	to_top(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (cheapest != *a && cheapest->target != *b)
	{
		if (cheapest->above_median && cheapest->target->above_median)
			rr(a, b);
		else if (!cheapest->above_median && !cheapest->target->above_median)
			rrr(a, b);
		else
			break ;
	}
	while (cheapest != *a)
	{
		if (cheapest->above_median)
			ra(a);
		else
			rra(a);
	}
	while (cheapest->target != *b)
	{
		if (cheapest->target->above_median)
			rb(b);
		else
			rrb(b);
	}
}

void	push_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = find_cheapest(*a);
	to_top(a, b, cheapest);
	pb(a, b);
}

// find closest bigger number
void	find_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*curr_a;
	t_stack_node	*target;
	int				curr_target;

	curr_target = INT_MAX;
	curr_a = a;
	while (curr_a)
	{
		if (curr_a->content > b->content && curr_a->content <= curr_target)
		{
			curr_target = curr_a->content;
			target = curr_a;
		}
		curr_a = curr_a->next;
	}
	if (curr_target == INT_MAX)
		b->target = find_min(a);
	else
		b->target = target;
}

void	push_b_to_a(t_stack_node **b, t_stack_node **a)
{
	while ((*b)->target != *a)
	{
		if ((*b)->target->above_median)
			ra(a);
		else
			rra(a);
	}
	pa(b, a);
}

void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min;

	min = find_min(*a);
	while ((*a)->content != min->content)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}
