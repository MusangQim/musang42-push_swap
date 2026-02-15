/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 20:32:12 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/15 21:46:26 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks()
{
}

void	push_to_a()
{
}

int	find_target_position(t_node **stack_a,  int element_index)
{
	int			position;
	t_node		*current;
	t_node		*target_node;

	position = 0;
	current = *stack_a;
	while (current)
	{
		if (element_index < current->index)
		{
			target_node = current;
			break;
		}
		current = current->next;
		position++;
	}
	if (element_index > max(*stack_a))
	{
		target_node = NULL;
		position = stack_size(stack_a);
	}
	return (position)(target_node);
}

void	get_max_index(t_node *stack)
{
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
