/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:11:23 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/24 16:30:28 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_node	*find_min_unindex(t_node *stack)
{
	t_node	*cursor;
	t_node	*min_node;

	min_node = NULL;
	cursor = stack;
	while (cursor != NULL)
	{
		if (cursor->index == -1)
			if (min_node == NULL || cursor->value < min_node->value)
				min_node = cursor;
		cursor = cursor->next;
	}
	return (min_node);
}

void	assign_index(t_node *stack)
{
	t_node	*node;
	int		index;

	index = 0;
	node = find_min_unindex(stack);
	while (node != NULL)
	{
		node->index = index;
		index++;
		node = find_min_unindex(stack);
	}
}
