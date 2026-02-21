/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:36:24 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/23 16:47:23 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_long(unsigned long n)
{
	int		length;
	char	*base;

	length = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		length += ft_puthex_long(n / 16);
	length += ft_putchar(base[n % 16]);
	return (length);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				length;

	address = (unsigned long)ptr;
	length = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	length += write(1, "0x", 2);
	length += ft_puthex_long(address);
	return (length);
}
