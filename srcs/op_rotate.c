/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:40:03 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/04 14:29:47 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack_node **head)
{
	t_stack_node	*last;

	if (!*head || !(*head)->next)
		return ;
	last = find_last(*head);
	*head = (*head)->next;
	last->next = (*head)->prev;
	(*head)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
	update_index(*a);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
	update_index(*b);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	update_index(*a);
	update_index(*b);
}
