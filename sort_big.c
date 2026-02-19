/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:32:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/19 16:06:41 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

}
