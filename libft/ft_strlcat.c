/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:40:46 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/12 12:28:05 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	srclength;
	size_t	destlength;

	srclength = 0;
	destlength = 0;
	while (dest[destlength] && destlength < destsize)
		destlength++;
	while (src[srclength])
		srclength++;
	if (destlength == destsize)
		return (destsize + srclength);
	i = 0;
	while (src[i] && (destlength + i + 1) < destsize)
	{
		dest[destlength + i] = src[i];
		i++;
	}
	dest[destlength + i] = '\0';
	return (destlength + srclength);
}
