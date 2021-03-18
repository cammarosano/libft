/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcammaro <rcammaro@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 06:57:37 by rcammaro          #+#    #+#             */
/*   Updated: 2021/01/27 14:23:56 by rcammaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	*free_return_null(void *ptr)
{
	free(ptr);
	return (NULL);
}

int		va_end_return(va_list args)
{
	va_end(args);
	return (-1);
}

int		unsuported(char *message)
{
	write(2, message, ft_strlen(message));
	return (-1);
}
