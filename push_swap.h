/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:24:52 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/06 14:31:30 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

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
int		position_by_index(t_node *stack, int indexvalue);

/* PARSE */
void	parse_args(int argc, char **argv, t_node **stack_a);

/* ERROR */
void	check_errors(char **argv, t_node **stack_a);

/* ERROR UTILS */
int		help_overflow(long num, int digit, int sign);
void	error_exit(t_node **stack);

/* INDEX */
void	assign_index(t_node *stack);

/* OPERATION */
void	push_a(t_node **stack_a, t_node **stack_b);
void	push_b(t_node **stack_a, t_node **stack_b);

void	swap_a(t_node **stack_a);
void	swap_b(t_node **stack_b);
void	swap_s(t_node **stack_a, t_node **stack_b);

void	rotate_a(t_node **stack_a);
void	rotate_b(t_node **stack_b);
void	rotate_r(t_node **stack_a, t_node **stack_b);

void	revrotate_a(t_node **stack_a);
void	revrotate_b(t_node **stack_b);
void	revrotate_r(t_node **stack_a, t_node **stack_b);

/* SORT SMALL */
void	sort_2(t_node **stack_a);
void	sort_3(t_node **stack_a);
void	sort_4(t_node **stack_a);
void	sort_5(t_node **stack_a);
void	sort_small(t_node **stack_a);

/* SORT BIG */
void	push_chunks(t_node **stack_a, t_node **stack_b);
void	rebuild_stack(t_node **stack_a, t_node **stack_b);
void	sort_big(t_node **stack_a, t_node **stack_b);

/* SORT BIG UTILS */
int		cost_a(t_node *stack_a, int index);
int		cost_b(t_node *stack_b, int index);
int		find_cheapest(t_node *stack_b, t_node *stack_a);
int		find_target(t_node *stack_a, int value);
int		get_value_index(t_node *stack, int index);

/* SORT BIG UTILS_2 */
void	shift_stacks(t_node **stack_a);
void	rotate_top_b(t_node **stack_b, int cheapest);
void	rotate_pos_a(t_node **stack_a, int target_pos);

/* UTILS */
void	free_stack(t_node **stack);

#endif
