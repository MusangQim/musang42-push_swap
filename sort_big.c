/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:32:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/07 20:20:26 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push all stack A to stack B */
void	push_chunks(t_node **stack_a, t_node **stack_b)
{
	int	push_in;
	int	chunk_size;
	int	currentlimit;

	push_in = 0;
	chunk_size = stack_size(*stack_a);
	if (chunk_size == 0)
		chunk_size = 1;
	else if (chunk_size <= 100)
		chunk_size = chunk_size / 5;
	else if (chunk_size <= 500)
		chunk_size = chunk_size / 20;
	else
		chunk_size = chunk_size / 50;
	currentlimit = chunk_size;
	while (*stack_a != NULL)
	{
		if (push_in >= chunk_size)
		{
			currentlimit += chunk_size;
			push_in = 0;
		}
		if ((*stack_a)->index < currentlimit)
		{
			push_b(stack_a, stack_b);
			push_in++;
		}
		else
			rotate_a(stack_a);
	}
}

/* use greedy to fix operation for efficieny */
void	rebuild_stack(t_node **stack_a, t_node **stack_b)
{
	int	value;
	int	cheapest;
	int	target_pos;

	while (*stack_b != NULL)
	{
		cheapest = find_cheapest(*stack_b, *stack_a);
		value = get_value_index(*stack_b, cheapest);
		target_pos = find_target(*stack_a, value);
		rotate_top_b(stack_b, cheapest);
		rotate_pos_a(stack_a, target_pos);
		push_a(stack_a, stack_b);
	}
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	assign_index(*stack_a);
	push_chunks(stack_a, stack_b);
	rebuild_stack(stack_a, stack_b);
	shift_stacks(stack_a);
}
