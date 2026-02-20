/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:32:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/20 11:19:03 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks(t_node **stack_a, t_node **stack_b)
{
	int	push_in;
	int	chunk_size
	int	currentlimit;

	push_in = 0;
	chunk_size = stack_size(*stack_a) / 5;
	if (chunk_size == 0)
		chunk_size = 1;
	currentlimit = chunk_size;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index <= currentlimit)
		{
			push_b(stack_a, stack_b);
			push_in++;
		}
		else
			rotate_a(stack_a);
		if (push_in == chunk_size)
		{
			currentlimit += chunk_size;
			push_in = 0;
		}
	}
}

int	find_max_index(t_node *stack)
{
	t_node		*current;
	int			max_index;

	if (!stack)
		return (0);
	max_index = stack->index;
	current = stack;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

void	rebuild_stack(t_node **stack_a, t_node **stack_b)
{
	int	pos;
	int	size;
	int	max_index;

	while (*stack_b != NULL)
	{
		size = stack_size(*stack_b);
		max_index = find_max_index(*stack_b);
		pos = position(*stack_b, max_index);
		if (pos <= size / 2)
			while ((*stack_b)->index != max_index)
				rotate_b(stack_b);
		else
			while ((*stack_b)->index != max_index)
				revrotate(stack_b);
		push_a(stack_a, stack_b);
	}
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	assign_index(*stack_a);
	push_chunks(*stack_a, *stack_b);
	rebuild_stack(*stack_a, *stack_b);
}
