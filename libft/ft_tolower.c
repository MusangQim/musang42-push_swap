/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 22:56:21 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/11 22:59:35 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int	low_value;

	if (c >= 'A' && c <= 'Z')
	{
		low_value = c + 32;
		return (low_value);
	}
	else
	{
		return (c);
	}
}
