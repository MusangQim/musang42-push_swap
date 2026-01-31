/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:17:37 by adzmusta          #+#    #+#             */
/*   Updated: 2026/01/31 21:26:06 by adzmusta         ###   ########.fr       */
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

static void	check_sign()
{
}

static void	check_overflow()
{
}

static void	check_duplicate()
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
