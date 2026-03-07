/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:17:37 by adzmusta          #+#    #+#             */
/*   Updated: 2026/03/07 18:53:13 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_invalidchar(char *str, t_node **stack_a)
{
	int	j;

	j = 0;
	if (str[j] == '+' || str[j] == '-')
		j++;
	if (str[j] == '\0')
	{
		write (2, "Error\n", 6);
		exit(1);
	}
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

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (ft_strlen(str + i) > (size_t)10)
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	while (str[i])
	{
		num = help_overflow(num, str[i] - '0', sign);
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
		if (argv[i][0] == '\0')
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		check_invalidchar(argv[i], stack_a);
		check_sign(argv[i], stack_a);
		value = check_overflow(argv[i]);
		stack_push(stack_a, create_node(value));
		i++;
	}
	check_duplicate(stack_a);
}
