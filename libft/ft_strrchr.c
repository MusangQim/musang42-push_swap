/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 23:43:00 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/12 00:07:24 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*last;

	last = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			last = (char *)&str[i];
		i++;
	}
	if ((char)ch == '\0')
		return ((char *)&str[i]);
	return (last);
}
