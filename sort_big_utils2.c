/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:15:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/06 14:23:32 by adzmusta         ###   ########.fr       */
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

void	rotate_top_b(t_node **stack_b, int cheapest)
{
	int	pos;
	int	size;

	pos = position_by_index(*stack_b, cheapest);
	size = stack_size(*stack_b);
	if (pos <= size / 2)
		while ((*stack_b)->index != cheapest)
			rotate_b(stack_b);
	else
		while ((*stack_b)->index != cheapest)
			revrotate_b(stack_b);
}

void	rotate_pos_a(t_node **stack_a, int target_pos)
{
	int	count;
	int	size;

	size = stack_size(*stack_a);
	if (target_pos <= size / 2)
	{
		count = target_pos;
		while (count-- > 0)
			rotate_a(stack_a);
	}
	else
	{
		count = size - target_pos;
		while (count-- > 0)
			revrotate_a(stack_a);
	}
}
