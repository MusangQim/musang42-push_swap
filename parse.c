/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:16:29 by adzmusta          #+#    #+#             */
/*   Updated: 2026/01/30 18:28:31 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(int argc, char **argv, t_stack **stack_a)
{
	char	**numbers;
	int		i;

	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	i = 0;
	while (numbers[i])
}
