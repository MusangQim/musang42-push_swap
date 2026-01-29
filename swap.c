/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:49:15 by adzmusta          #+#    #+#             */
/*   Updated: 2026/01/29 14:31:04 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_process(t_node **stack)
{
	t_node	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	swap_a(t_node **stack_a)
{
	swap_process(stack_a);
}

void	swap_b(t_node **stack_b)
{
	swap_process(stack_b);
}

void	swap_s(t_node **stack_a, t_node **stack_b)
{
	swap_process(stack_a);
	swap_process(stack_b);
}
