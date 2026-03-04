/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:32:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/05 04:12:36 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_a(t_node *stack_a, int index)
{
	int	pos;
	int	size;

	pos = position_by_index(stack_a, index);
	size = stack_size(stack_a);
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

int	cost_b(t_node *stack_b, int index)
{
	int	pos;
	int	size;

	pos = position_by_index(stack_b, index);
	size = stack_size(stack_b);
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

int	find_cheapest(t_node *stack_b, t_node *stack_a)
{
	t_node		*current;
	int			min_cost;
	int			total_cost;
	int			cheapest;

	current = stack_b;
	min_cost = INT_MAX;
	cheapest = 0;
	while (current != NULL)
	{
		total_cost = cost_b(stack_b, current->index)
			+ cost_a(stack_a, current->index);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = current->index;
		}
		current = current->next;
	}
	return (cheapest);
}

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

/* use greedy to fix operation for efficieny */
void	rebuild_stack(t_node **stack_a, t_node **stack_b)
{
	int	pos;
	int	size;
	int	max_index;

	while (*stack_b != NULL)
	{
		size = stack_size(*stack_b);
		max_index = find_max_index(*stack_b);
		pos = position_by_index(*stack_b, max_index);
		if (pos <= size / 2)
			while ((*stack_b)->index != max_index)
				rotate_b(stack_b);
		else
			while ((*stack_b)->index != max_index)
				revrotate_b(stack_b);
		push_a(stack_a, stack_b);
	}
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	assign_index(*stack_a);
	push_chunks(stack_a, stack_b);
	rebuild_stack(stack_a, stack_b);
}
