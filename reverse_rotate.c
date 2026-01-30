/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:54:46 by adzmusta          #+#    #+#             */
/*   Updated: 2026/01/29 23:30:21 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_process(t_node **stack)
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

void	reverse_a(t_node **stack_a)
{
}

void	reverse_b(t_node **stack_b)
{
}

void	reverse_r(t_node **stack_a, t_node **stack_b)
{
}
