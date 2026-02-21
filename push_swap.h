/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:24:52 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/21 10:19:51 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* STACK */
t_node	*create_node(int value);
void	stack_push(t_node **stack, t_node *new);
int		stack_size(t_node *stack);

/* STACK UTILS */
int		min(t_node *stack);
int		max(t_node *stack);
int		is_sorted(t_node *stack);
int		position(t_node *stack, int value);

#endif
