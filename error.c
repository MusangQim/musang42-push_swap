/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:17:37 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/06 16:18:52 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_invalidchar(char *str, t_node **stack_a)
{
	int	j;

	j = 0;
	if (str[j] == '+' || str[j] == '-')
		j++;
	while (str[j] != '\0')
	{
		if (!ft_isdigit(str[j]))
		{
			error_exit(stack_a);
		}
		j++;
	}
}

static void	check_sign(char *str, t_node **stack_a)
{
	int	j;

	j = 0;
	if (str[j] == '+' || str[j] == '-')
		j++;
	while (str[j] != '\0')
	{
		if (str[j] == '+' || str[j] == '-')
		{
			error_exit(stack_a);
		}
		j++;
	}
}

static int	check_overflow(char *str)
{
	long	num;
	int		i;
	int		sign;
	int		digit;

	i = 0;
	num = 0;
	sign = +1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		digit = str[i] - '0';
		num = help_overflow(num, digit, sign);
		i++;
	}
	return ((int)(num * sign));
}

static void	check_duplicate(t_node **stack_a)
{
	t_node	*current;
	t_node	*runner;

	current = *stack_a;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->value == runner->value)
			{
				error_exit(stack_a);
			}
			runner = runner->next;
		}
		current = current->next;
	}
}

void	check_errors(char **argv, t_node **stack_a)
{
	int	i;
	int	value;

	i = 0;
	while (argv[i])
	{
		check_invalidchar(argv[i], stack_a);
		check_sign(argv[i], stack_a);
		check_overflow(argv[i]);
		value = ft_atoi(argv[i]);
		stack_push(stack_a, create_node(value));
		i++;
	}
	check_duplicate(stack_a);
}
