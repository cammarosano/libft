/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:27:58 by rcammaro          #+#    #+#             */
/*   Updated: 2020/11/24 19:55:33 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = (n < 0) ? -1 : 1;
	if (n > -10 && n < 10)
	{
		if (sign == -1)
			ft_putchar_fd('-', fd);
		ft_putchar_fd(n * sign + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 * sign + '0', fd);
	}
}
