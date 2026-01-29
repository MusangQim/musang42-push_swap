/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 23:59:33 by adzmusta          #+#    #+#             */
/*   Updated: 2026/01/29 12:47:15 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_process(t_node **src, t_node **dest)
{
	t_node	tmp;

	if (!= src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	push_a(t_node **stack_a, t_node **stack_b)
{
	push_process(stack_a, stack_b);
}

void	push_b(t_node **stack_a, t_node **stack_b)
{
	push_process(stack_b, stack_a);
}
