/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:20:23 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/14 15:36:45 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	trim_front(const char *s1, const char *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && in_set(s1[i], set))
		i++;
	return (i);
}

static size_t	trim_back(const char *s1, const char *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > 0 && in_set(s1[end - 1], set))
		end--;
	return (end);
}

static char	*after_trim(void)
{
	char	*new_str;

	new_str = malloc(1);
	if (!new_str)
		return (NULL);
	new_str[0] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		front;
	size_t		back;
	size_t		length;
	size_t		i;
	char		*new_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	front = trim_front(s1, set);
	back = trim_back(s1, set);
	if (front >= back)
		return (after_trim());
	length = back - front;
	new_str = malloc(length + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		new_str[i] = s1[front + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
