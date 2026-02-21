/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:29:45 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/23 15:10:05 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 10)
		length += ft_putunbr(n / 10);
	length += ft_putchar((n % 10) + '0');
	return (length);
}
