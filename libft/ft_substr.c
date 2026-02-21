/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 18:48:10 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/13 14:43:43 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_str(void)
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (NULL);
	*s = '\0';
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		real_len;
	size_t		index;
	char		*new_str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		return (empty_str());
	}
	real_len = ft_strlen(s) - start;
	if (real_len > len)
		real_len = len;
	new_str = malloc(real_len + 1);
	if (!new_str)
		return (NULL);
	index = 0;
	while (index < real_len)
	{
		new_str[index] = s[start + index];
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
