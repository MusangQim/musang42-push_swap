/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:21:28 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/10 17:32:53 by adzmusta         ###   ########.fr       */
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
	t_node		node_max;
	int			sort;

	sort = is_sorted(stack_a);
	if (sort)
		return ;
	node_max = max(stack_a);
	if (node_max == (*stack_a))
		rotate_a(stack_a);
	else if (node_max == (*stack_a)->next)
		revrotate_a(stack_a);
	else
		swap_a(stack_a);
}

int	sort_5(t_node **stack_a)
{
}

int	sort_small(t_node **stack_a)
{
}
