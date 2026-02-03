/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:17:37 by adzmusta          #+#    #+#             */
/*   Updated: 2026/02/03 18:54:17 by adzmusta         ###   ########.fr       */
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
}

static void	check_duplicate(char **argv)
{
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
