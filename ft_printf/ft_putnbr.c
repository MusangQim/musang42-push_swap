/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:24:01 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/23 12:27:27 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long		number;
	int			length;

	number = n;
	length = 0;
	if (number < 0)
	{
		length += write(1, "-", 1);
		number = -number;
	}
	if (number >= 10)
		length += ft_putnbr(number / 10);
	length += ft_putchar((number % 10) + '0');
	return (length);
}
