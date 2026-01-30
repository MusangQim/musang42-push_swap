/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 22:43:17 by adzmusta          #+#    #+#             */
/*   Updated: 2026/01/30 11:11:02 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_process(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
}

void	rotate_a(t_node **stack_a)
{
	rotate_process(stack_a);
	ft_putstr("ra\n");
}

void	rotate_b(t_node **stack_b)
{
	rotate_process(stack_b);
	ft_putstr("rb\n");
}

void	rotate_r(t_node **stack_a, t_node **stack_b)
{
	rotate_process(stack_a);
	rotate_process(stack_b);
	ft_putstr("rr\n");
}
