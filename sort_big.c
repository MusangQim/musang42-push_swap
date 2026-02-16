/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:32:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/16 16:01:31 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks()
{
}

void	push_to_a()
{
}

int	find_target_position(t_node **stack_a, t_node **target_node, int element_index)
{
	int			position;
	t_node		*current;

	position = 0;
	current = *stack_a;
	while (current)
	{
		if (element_index < current->index)
		{
			*target_node = current;
			break;
		}
		current = current->next;
		position++;
	}
	if (element_index > max(*stack_a))
	{
		*target_node = NULL;
		position = stack_size(stack_a);
	}
	return (position);
}

void	calculate_cost(t_node **stack_a, t_node **stack_b)
{
	int	moves_a;
	int	moves_b;
	int	pos_in_a;
	int	pos_in_b;
	int	direction_a;
	int	direction_b;
	int	total_cost;

	pos_in_a = find_target_position(stack_a, &target_node, stack_b->index);
	pos_in_b = position(stack_b, stack_b->node);
	if (pos_in_a <= stack_size(stack_a) / 2)
	{
		direction_a = rotate_a(stack_a);
		moves_a = pos_in_a;
	}
	else
	{
		direction_a = revrotate_a(stack_a);
		moves_a = stack_size(stack_a) - pos_in_a;
	}
	if (pos_in_b <= stack_size(stack_b) / 2)
	{
		direction_b = rotate_b(stack_b);
		moves_b = pos_in_b;
	}
	else
	{
		direction_b = revrotate_b(stack_b);
		moves_b = stack_size(stack_b) - pos_in_b;
	}
	if (direction_a == direction_b)
		total_cost = max(moves_a, moves_b);
	else
		total_cost = moves_a + moves_b;			
}


void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	element;
	int	chunk_size;
	int	find_max;

	if (is_sorted(*stack_a))
		return ;
	chunk_size = calculate_chunk_size(stack_a);
	while (!stack_a)
	{
		element = find_next_chunk(stack_a, chunk_size);
		if (position(element) < stack_size(*stack_a) / 2)
			rotate_a(stack_a);
		else
			revrotate_a(stack_a);
		push_b(stack_a);
	}
	while (!stack_b)
	{
		find_max = get_max_index(stack_b);
		target_pos(
		if (position(max

}
