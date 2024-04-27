/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:44:25 by nusamank          #+#    #+#             */
/*   Updated: 2024/02/22 11:37:47 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*result;

	result = (char *)str;
	while (*result)
	{
		if (*result == (unsigned char)c)
			return (result);
		result++;
	}
	if (*result == (unsigned char)c || c == 0)
		return (result);
	return (NULL);
}
