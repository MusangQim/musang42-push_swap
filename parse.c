/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:16:29 by adzmusta          #+#    #+#             */
/*   Updated: 2026/01/30 19:36:06 by adzmusta         ###   ########.fr       */
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

void	parse_args(int argc, char **argv, t_stack **stack_a)
{
	char	**numbers;
	int		i;

	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = &argv[1];
	i = 0;
	while (numbers[i])
	{
		if (!is_validnum(numbers[i]))
			error_exit("Error\n");
		value = ft_atoi(numbers[i]);
		push_stack(stack_a, create_node(value));
		i++;
	}
	if (argc == 2)
		free_split(numbers);
}
