/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:17:37 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/04 22:16:05 by adzmusta         ###   ########.fr       */
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
	long	number;
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
	t_node *runner;
}

void	check_errors(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		check_invalidchar(argv[i]);
		check_sign(argv[i]);
		check_overflow(argv[i]);
		i++;
	}
	check_duplicate(argv);
}
