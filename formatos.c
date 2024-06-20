/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:33:57 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/06/20 16:05:59 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)//c y %
{
	write(1, &c, sizeof(char) * 1);
	return (1);
}

int	ft_putstring(char *str)//s
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putptr(void *ptr)//p
{
	unsigned long	address;
	int				count;

	address = (unsigned long)ptr;
	count = 0;
	if (ptr == NULL)
		count += write(1, "(nil)", 5);
	else
	{
		count += ft_putstring("0x");
		count += ft_putnbr16(address, 0);
	}
	return (count);
}
