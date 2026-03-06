/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 09:13:00 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/06 15:11:05 by adzmusta         ###   ########.fr       */
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

int	find_target(t_node *stack_a, int value)
{
	t_node		*current;
	int			pos;
	int			best_value;
	int			target_pos;

	current = stack_a;
	pos = 0;
	target_pos = 0;
	best_value = INT_MAX;
	while (current)
	{
		if (current->value > value && current->value < best_value)
		{
			best_value = current->value;
			target_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (best_value == INT_MAX)
		target_pos = position(*stack_a, min(*stack_a));
	return (target_pos);
}

int	get_value_index(t_node *stack, int index)
{
	while (stack)
	{
		if (stack->index == index)
			return (stack->value);
		stack = stack->next;
	}
	return (0);
}
