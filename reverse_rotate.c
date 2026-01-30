/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:54:46 by adzmusta          #+#    #+#             */
/*   Updated: 2026/01/30 11:23:54 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	revrotate_process(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (tmp->next)
		last = last->next;
	last->next = tmp;
}

void	revrotate_a(t_node **stack_a)
{
	revrotate_process(stack_a);
}

void	revrotate_b(t_node **stack_b)
{
	revrotate_process(stack_b);
}

void	revrotate_r(t_node **stack_a, t_node **stack_b)
{
	revrotate_process(stack_a);
	revrotate_process(stack_b);
}
