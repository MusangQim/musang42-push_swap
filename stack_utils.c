/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:17:22 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/01 07:23:05 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min(t_node *stack)
{
	t_node		*current;
	int			min_value;

	if (!stack)
		return (0);
	min_value = stack->value;
	current = stack;
	while (current)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	return (min_value);
}

int	max(t_node *stack)
{
	t_node		*current;
	int			max_value;

	if (!stack)
		return (0);
	max_value = stack->value;
	current = stack;
	while (current)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	return (max_value);
}

int	is_sorted(t_node *stack)
{
	t_node	*current;

	if (!stack || !stack->next)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	position(t_node *stack, int value)
{
	t_node		*current;
	int			index;

	current = stack;
	index = 0;
	while (current)
	{
		if (current->value == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

int	position_by_index(t_node *stack, int indexvalue)
{
	t_node		*current;
	int			pos;

	current = stack;
	pos = 0;
	while (current)
	{
		if (current->index == indexvalue)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}
