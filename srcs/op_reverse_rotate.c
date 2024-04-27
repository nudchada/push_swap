/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:45:01 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/04 14:30:02 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack_node **head)
{
	t_stack_node	*last;

	if (!*head || !(*head)->next)
		return ;
	last = find_last(*head);
	last->next = *head;
	last->prev->next = NULL;
	(*head)->prev = last;
	*head = last;
	(*head)->prev = NULL;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
	update_index(*a);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
	update_index(*b);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
	update_index(*a);
	update_index(*b);
}
