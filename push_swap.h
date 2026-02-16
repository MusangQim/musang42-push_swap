/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:24:52 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/16 16:09:48 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node
{
	int				value;
	int				index;
	int				moves_a;
	int				moves_b;
	int				direction_a;
	int				direction_b;
	int				total_cost;
	struct s_node	*next;
}	t_node;
