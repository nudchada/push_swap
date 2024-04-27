/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:46:58 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/04 14:27:59 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*top_node;

	if (!*src)
		return ;
	top_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	top_node->next = *dst;
	if (*dst)
		(*dst)->prev = top_node;
	*dst = top_node;
	top_node->prev = NULL;
}

void	pa(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	ft_printf("pa\n");
	update_index(*a);
	update_index(*b);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pb\n");
	update_index(*a);
	update_index(*b);
}
