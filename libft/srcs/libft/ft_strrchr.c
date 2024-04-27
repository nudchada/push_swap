/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nusamank <nusamank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:50:18 by nusamank          #+#    #+#             */
/*   Updated: 2024/02/22 11:38:38 by nusamank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*result;

	result = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			result = (char *)str;
		str++;
	}
	if (*str == (unsigned char)c || c == 0)
		result = (char *)str;
	return (result);
}
