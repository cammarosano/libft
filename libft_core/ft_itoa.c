/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:01:17 by rcammaro          #+#    #+#             */
/*   Updated: 2020/11/24 19:25:30 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	digits;

	digits = 1;
	if (n < 0)
		digits = 2;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		sign;

	sign = (n < 0) ? -1 : 1;
	size = get_size(n);
	if (!(str = malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	str[size--] = '\0';
	while (n >= 10 || n <= -10)
	{
		str[size--] = (n % 10) * sign + '0';
		n /= 10;
	}
	str[size--] = (n % 10) * sign + '0';
	if (sign == -1)
		str[size] = '-';
	return (str);
}
