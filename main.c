/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 23:45:21 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/23 00:03:04 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	assign_index(stack_a);
	if (stack_size(stack_a) < 5)
		sort_small(stack_a);
	else
		sort_big(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
