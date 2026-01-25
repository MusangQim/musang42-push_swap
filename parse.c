/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:16:29 by adzmusta          #+#    #+#             */
/*   Updated: 2026/01/25 23:07:30 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(argc, **argv, &stack_a)
{
	char	**numbers;
	int		value;
	int		i;

	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = &argv[1];
	i = 0;
	while (numbers[i])
	{
		value = ft_atoi(numbers[i]);
		t_stack	*new_node = create_node(value);
		stack_push(stack_a, new_node);
		i++;
	}
	if (argc == 2)
		free_split(numbers);
}
