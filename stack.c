/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:22:10 by adzmusta          #+#    #+#             */
/*   Updated: 2026/01/22 21:53:16 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* buat node
 * -allocate memory
 *  -isi value
 *  -next = NULL
 */
t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(size_of (t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

/* add element kat atas stack */
void	stack_push(t_node **stack, t_node *new)
{
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
	/* or can be:
	 * if (!*stack)
	 * {
	 * 	*stack = new;
	 * 	return ;
	 * }
	 */
}

/* return no of element dalam stack */
int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (NULL);
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
