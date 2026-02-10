/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:21:28 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/10 20:42:34 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack_a)
{
	int	sort;

	sort = is_sorted(stack_a);
	if (sort)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}

void	sort_3(t_node **stack_a)
{
	int	node_max;
	int	sort;

	sort = is_sorted(stack_a);
	if (sort)
		return ;
	node_max = max(*stack_a);
	if (node_max == (*stack_a)->value)
		rotate_a(stack_a);
	else if (node_max == (*stack_a)->next->value)
		revrotate_a(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
}

void	sort_5(t_node **stack_a)
{
	int	node_min;
	int	sort;
	int	size;
	t_node		*stack_b;

	stack_b = NULL;
	sort = is_sorted(stack_a);
	if (sort)
		return ;
	size = stack_size(*stack_a);
	node_min = min(*stack_a);
	while (size > 3)
	{
		if (node_min == (*stack_a)->value)
			push_b(stack_b);
		else if (node_min <= size/2)
			rotate_a(stack_a);
		else if (node_min > size/2)
			revrotate_a(stack_a);


}

int	sort_small(t_node **stack_a)
{
}
