/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:32:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/16 17:32:11 by adzmusta         ###   ########.fr       */
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

void	calculate_cost(t_node **stack_a, t_node *node_b, t_node *stack_b)
{
	int			pos_in_a;
	int			pos_in_b;
	t_node		*target_node;

	pos_in_a = find_target_position(stack_a, &target_node, node_b->index);
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

}
