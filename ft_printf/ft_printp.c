/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:20:01 by jbanchon          #+#    #+#             */
/*   Updated: 2024/11/18 17:56:42 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

size_t	ft_ptrlen(uintptr_t value)
{
	size_t	len;

	len = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= 16;
		len++;
	}
	return (len);
}

void	ft_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

void	ft_printp(unsigned long long value, int *counter)
{
	if (value == 0)
		(*counter) += write(1, "(nil)", 5);
	else
	{
		(*counter) += write(1, "0x", 2);
		ft_putptr(value);
		(*counter) += ft_ptrlen(value);
	}
}
