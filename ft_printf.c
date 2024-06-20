/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalvez- <fgalvez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:33:38 by fgalvez-          #+#    #+#             */
/*   Updated: 2024/06/20 16:08:43 by fgalvez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type(char format, va_list args)
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
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
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
			count += type(format[i], args);
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

// int  main(void)
// {
//  char            *str;
//  int             num;
//  unsigned int    unum;
//  void            *ptr;
//  str = "";
//  num = 4232412;
//  unum = -42;
//  ptr = &num;
//  int ret1, ret2;
//  printf("Testing string: \n");
//  ret1 = printf("%s\n", str);
//  ret2 = ft_printf("%s\n", str);
//  printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);
//  printf("Testing char: \n");
//  ret1 = printf("%c\n", 'a');
//  ret2 = ft_printf("%c\n", 'a');
//  printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);
//  printf("Testing integer: \n");
//  ret1 = printf("%d\n", -2147483647);
//  ret2 = ft_printf("%d\n", -2147483647);
//  printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);
//  printf("Testing unsigned integer: \n");
//  ret1 = printf("%u\n", unum);
//  ret2 = ft_printf("%u\n", unum);
//  printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);
//  printf("Testing hexadecimal: \n");
//  ret1 = printf("%x\n", num);
//  ret2 = ft_printf("%x\n", num);
//  printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);
//  printf("Testing uppercase hexadecimal: \n");
//  ret1 = printf("%X\n", num);
//  ret2 = ft_printf("%X\n", num);
//  printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);
//  printf("Testing pointer: \n");
//  ret1 = printf("%p\n", ptr);
//  ret2 = ft_printf("%p\n", ptr);
//  printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);
//  printf("Testing percentage: \n");
//  ret1 = printf("%%\n");
//  ret2 = ft_printf("%%\n");
//  printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);
//  printf("Testing NULL pointer: \n");
//  ret1 = printf("%p\n", NULL);
//  ret2 = ft_printf("%p\n", NULL);
//  printf("printf returned : %d, ft_printf returned: %d\n\n", ret1, ret2);
//  return (0);
// }