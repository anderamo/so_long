/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_perf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamorin- <aamorin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:49:08 by aamorin-          #+#    #+#             */
/*   Updated: 2021/08/05 12:43:19 by aamorin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_sign(char *str)
{
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		return (1);
	else
		return (0);
}

int	check_limits(long number, int sign)
{
	if (number * sign <= -2147483649 || number * sign >= 2147483648)
	{
		ft_printf("Error\n");
		exit (1);
	}
	else
		return (number * sign);
}

long	ft_atoi_perf(char *str)
{
	size_t				i;
	int					sign;
	long				number;

	number = 0;
	i = 0;
	sign = check_sign(str);
	if (sign == -1 || sign == 1)
		i++;
	if (sign == 0)
		sign = 1;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_printf("Error: '%s' is not a number\n", str);
			exit(1);
		}
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (check_limits(number, sign));
}
