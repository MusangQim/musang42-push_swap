/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:15:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/06 14:17:36 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_stacks(t_node **stack_a)
{
	int	low_pos;
	int	size;

	low_pos = position(*stack_a, min(*stack_a));
	size = stack_size(*stack_a);
	if (low_pos <= size / 2)
		while ((*stack_a)->value != min(*stack_a))
			rotate_a(stack_a);
	else
		while ((*stack_a)->value != min(*stack_a))
			revrotate_a(stack_a);
}

void
