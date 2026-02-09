/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:21:28 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/09 23:27:44 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_node **stack_a)
{
	int	sort;

	sort = is_sorted(stack_a);
	if (sort)
		return (0);
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap_a(stack_a);
	return (stack_a);
}

void	sort_3()
{

}

int	sort_5(t_node)
{

}

int	sort_small(t_node **stack_a)
{

}

