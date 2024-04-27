/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:44:05 by nusamank          #+#    #+#             */
/*   Updated: 2024/04/11 17:16:10 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long	my_custom_atol(const char *nptr, bool *error)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + *nptr - '0';
		nptr++;
	}
	if (*nptr)
		*error = true;
	num *= sign;
	if (num < INT_MIN || num > INT_MAX)
		*error = true;
	return (num);
}

static bool	check_duplicate(t_stack_node **a, int num)
{
	t_stack_node	*node;

	node = *a;
	while (node)
	{
		if (node->content == num)
			return (true);
		node = node->next;
	}
	return (false);
}

static void	append_node(t_stack_node **a, int num)
{
	t_stack_node	*node;
	t_stack_node	*last;

	if (!a)
		return ;
	node = (malloc(sizeof(t_stack_node)));
	if (!node)
		return ;
	node->content = num;
	node->next = NULL;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last(*a);
		last->next = node;
		node->prev = last;
	}
}

void	init_stack(t_stack_node **a, char **nums)
{
	long			long_num;
	int				num;
	int				i;
	bool			error;

	i = 0;
	error = false;
	if (!nums[i])
	{
		free_array(nums);
		handle_errors(a);
	}
	while (nums[i])
	{
		long_num = my_custom_atol(nums[i], &error);
		num = (int)long_num;
		if (error || check_duplicate(a, num))
		{
			free_array(nums);
			handle_errors(a);
		}
		append_node(a, num);
		i++;
	}
	free_array(nums);
}
