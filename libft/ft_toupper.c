/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 22:48:53 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/11 22:56:01 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	up_value;

	if (c >= 'a' && c <= 'z')
	{
		up_value = c - 32;
		return (up_value);
	}
	else
	{
		return (c);
	}
}
