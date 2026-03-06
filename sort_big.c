/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:32:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/06 12:48:42 by adzmusta         ###   ########.fr       */
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
		chunk_size = chunk_size / 7;
	else if (chunk_size <= 500)
		chunk_size = chunk_size / 5;
	else
		chunk_size = chunk_size / 17;
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
		{
			if ((*stack_b) != NULL)
				rotate_r(stack_a, stack_b);
			else
				rotate_a(stack_a);
		}
	}
}

static void	shift_stacks(t_node **stack_a)
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

/* use greedy to fix operation for efficieny */
void	rebuild_stack(t_node **stack_a, t_node **stack_b)
{
	int	pos;
	int	size;
	int	cheapest;

	while (*stack_b != NULL)
	{
		cheapest = find_cheapest(*stack_b, *stack_a);
		pos = position_by_index(*stack_b, cheapest);
		size = stack_size(*stack_b);
		if (pos <= size / 2)
			while ((*stack_b)->index != cheapest)
				rotate_b(stack_b);
		else
			while ((*stack_b)->index != cheapest)
				revrotate_b(stack_b);
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
