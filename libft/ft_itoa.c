/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzmusta <adzmusta@student.42iskandarpute  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:57:52 by adzmusta          #+#    #+#             */
/*   Updated: 2025/10/18 21:22:08 by adzmusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long temp)
{
	int	count;

	count = 0;
	if (temp < 0)
		temp = -temp;
	while (temp != 0)
	{
		temp = temp / 10;
		count++;
	}
	return (count);
}

static int	total_length(int count, int sign)
{
	int	total_length;

	if (sign == -1)
		total_length = count + 1;
	else
		total_length = count;
	return (total_length);
}

static char	*fill_string(long temp, int count, int total_length, int sign)
{
	char	*str;

	str = (char *)malloc(total_length + 1);
	if (!str)
		return (NULL);
	str[total_length] = '\0';
	while (count > 0)
	{
		total_length--;
		str[total_length] = (temp % 10) + '0';
		temp = temp / 10;
		count--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	int		total_len;
	int		sign;
	long	temp;

	if (n == 0)
		return (ft_strdup("0"));
	sign = 1;
	if (n < 0)
		sign = -1;
	temp = n;
	count = count_digit(temp);
	total_len = total_length(count, sign);
	if (n < 0)
		temp = (long)n * -1;
	else
		temp = n;
	return (fill_string(temp, count, total_len, sign));
}
