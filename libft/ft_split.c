/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:44:15 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/14 16:47:23 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	count;
	size_t	in_wd;

	count = 0;
	in_wd = 0;
	while (*s)
	{
		if (in_wd == 0 && *s != c)
		{
			in_wd = 1;
			count++;
		}
		else if (*s == c)
			in_wd = 0;
		s++;
	}
	return (count);
}

static int	word_length(const char *s, char c)
{
	int	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

static void	set_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		length;
	char	**result;

	if (s == NULL)
		return (NULL);
	result = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			length = word_length(s, c);
			result[i] = ft_substr(s, 0, length);
			if (!result[i])
				return (set_free(result), NULL);
			i++;
			s += length;
		}
	}
	return (result);
}
