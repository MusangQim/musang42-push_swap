/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:55:03 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/03 19:03:48 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	help_noverflow(long num, int digit, int sign)
{
	if (sign == +1)
	{
		if (num > (INT_MAX - digit) / 10)
		{
			ft_putstr("Error\n");
			exit(1);
		}
	}
	if (sign == -1)
	{
		if (num > ((long)INT_MAX + 1 - digit) / 10)
		{
			ft_putstr("Error\n");
			exit(1);
		}
	}
	num = num * 10 + digit;
	return (num);
}

