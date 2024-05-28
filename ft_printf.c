/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:33:38 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/05/28 21:37:00 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type(char format,va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstring(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_putnbr16(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count += ft_putnbr16(va_arg(args, unsigned int), 1);
	else if (format == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (format == '%')
	{
		count += ft_putchar('%');
		count++;
	}
	return (count);
}

int	ft_printf(const char *format,...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			count += type(format[i],args);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	int	count,count2,count3,count4;
	int	*ptr;

	//%d
	ptr = malloc(5 * sizeof(int));
	count = ft_printf("Formato d:%c", 'a');
	printf("\n");
	count2 = printf("Formato d:%c", 'a');
	printf("\n");
	printf("%d\n", count);
	printf("%d\n", count2);
	free(ptr);

	//%s
	count3 = ft_printf("Formato s:%s", "Hola"); //% %s ERROR SEGURO.
	printf("\n");
	count4 = printf("Formato s:%s", "Hola");
	printf("\n");
	printf("%d\n", count3);
	printf("%d\n", count4);
	return (0);
}
