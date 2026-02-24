/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:16:29 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/24 16:11:00 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	parse_args(int argc, char **argv, t_node **stack_a)
{
	char	**numbers;

	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = &argv[1];
	check_errors(numbers, stack_a);
	if (argc == 2)
		free_split(numbers);
}
