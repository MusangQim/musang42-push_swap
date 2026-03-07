/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:55:03 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/07 18:52:06 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	help_overflow(long num, int digit, int sign)
{
	if (sign == 1)
	{
		if (num > (INT_MAX - digit) / 10)
		{
			write (2, "Error\n", 6);
			exit(1);
		}
	}
	else
	{
		if (num > ((long)INT_MAX + 1 - digit) / 10)
		{
			write (2, "Error\n", 6);
			exit(1);
		}
	}
	return (num * 10 + digit);
}

void	error_exit(t_node **stack)
{
	write (2, "Error\n", 6);
	free_stack(stack);
	exit(1);
}
