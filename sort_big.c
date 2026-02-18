/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:32:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/18 12:57:35 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rebuild_stack(t_node **stack_a, t_node **stack_b)
{
	int	max_index;

	while (stack_b != NULL)
	{
		max_index = max(stack_b);
		if (max_index <= stack_size(stack_b) / 2)
			rotate_b(stack_b);
		else
			revrotate(stack_b);
	}
	push_a(stack_a);
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

void	sort_big(t_node **stack_a, t_node **stack_b)
{

}
