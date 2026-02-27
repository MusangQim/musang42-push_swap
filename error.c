/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:17:37 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/27 23:20:29 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_invalidchar(char *str)
{
	int	j;

	j = 0;
	if (str[j] == '+' || str[j] == '-')
		j++;
	while (str[j] != '\0')
	{
		if (!ft_isdigit(str[j]))
		{
			ft_putstr("Error\n");
			exit(1);
		}
		j++;
	}
}

static void	check_sign(char *str)
{
	int	j;

	j = 0;
	if (str[j] == '+' || str[j] == '-')
		j++;
	while (str[j] != '\0')
	{
		if (str[j] == '+' || str[j] == '-')
		{
			ft_putstr("Error\n");
			exit(1);
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

static void	check_duplicate(t_node *stack)
{
	t_node	*current;
	t_node	*runner;

	current = stack;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->value == runner->value)
			{
				ft_putstr("Error\n");
				exit(1);
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
		check_invalidchar(argv[i]);
		check_sign(argv[i]);
		check_overflow(argv[i]);
		value = ft_atoi(argv[i]);
		stack_push(stack_a, create_node(value));
		i++;
	}
	check_duplicate(*stack_a);
}
