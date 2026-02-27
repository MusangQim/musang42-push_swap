/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:21:28 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/27 23:03:15 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorting 2 node */
void	sort_2(t_node **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}

/* sorting 3 node */
void	sort_3(t_node **stack_a)
{
	int	node_max;

	node_max = max(*stack_a);
	if (node_max == (*stack_a)->value)
		rotate_a(stack_a);
	else if (node_max == (*stack_a)->next->value)
		revrotate_a(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}

/* sorting 4 node */
void	sort_4(t_node **stack_a)
{
	int			node_min;
	int			size;
	t_node		*stack_b;

	stack_b = NULL;
	while (stack_size(*stack_a) > 3)
	{
		node_min = min(*stack_a);
		size = stack_size(*stack_a);
		if (node_min == (*stack_a)->value)
			push_b(stack_a, &stack_b);
		else if (position(*stack_a, node_min) <= size / 2)
			rotate_a(stack_a);
		else
			revrotate_a(stack_a);
	}
	sort_3(stack_a);
	push_a(stack_a, &stack_b);
}

/* sorting 5 node */
void	sort_5(t_node **stack_a)
{
	int			node_min;
	int			size;
	t_node		*stack_b;

	stack_b = NULL;
	while (stack_size(*stack_a) > 3)
	{
		node_min = min(*stack_a);
		size = stack_size(*stack_a);
		if (node_min == (*stack_a)->value)
			push_b(stack_a, &stack_b);
		else if (position(*stack_a, node_min) <= size / 2)
			rotate_a(stack_a);
		else
			revrotate_a(stack_a);
	}
	sort_3(stack_a);
	if (stack_b && stack_b->next && stack_b->value > stack_b->next->value)
		swap_b(&stack_b);
	push_a(stack_a, &stack_b);
	push_a(stack_a, &stack_b);
}

/* all function in here */
void	sort_small(t_node **stack_a)
{
	int	sort;
	int	size;

	sort = is_sorted(*stack_a);
	if (sort)
		return ;
	size = stack_size(*stack_a);
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a);
	else if (size == 5)
		sort_5(stack_a);
}
