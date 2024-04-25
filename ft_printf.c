/* 1-Investigación.Comprobar que piden en 42, que formatos, que estructura,
cómo funciona ?
2-Planificación. Cómo vamos a hacerlo, que funciones necesitamos, que estructura
vamos a seguir, que vamos a hacer primero, que después, etc
	-Main que recorra la cadena de formato, funciones axuliares que manejen los formatos
3-Comenzaremos por los formatos mas simples
4-Entender como funciona va_list y manejarlo correctamente
5-Especificadores de formato numéricos, enteros y enteros sin signo
 convertir los número a cadenas de caracteres
6-Formatos hexadecimales, , convertirlos a base 16
7-Realiza las pruebas necesarias
8-refactorizar y optimizar
9- Documentar el código.
*/
/*
Nombre del programa: libftprintf.a
Funciones: malloc, free, write, va_start, va_arg, va_copy, va_end
sin buffer.

Completados:
• %p El puntero void * dado como argumento se imprime en formato hexadecimal.
• %i Imprime un entero en base 10.
• %u Imprime un número decimal (base 10) sin signo.
• %d Imprime un número decimal (base 10)
• %c Imprime un solo carácter.
• %s Imprime una string (como se define por defecto en C).
• % % para imprimir el símbolo del porcentaje
• %x Imprime un número hexadecimal (base 16) en minúsculas.
• %X Imprime un número hexadecimal (base 16) en mayúsculas.
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_putchar(int c)//c y %
{
	write(1, &c, sizeof(char) * 1);
	return (1);
}

char ft_putstring(char *str)//s
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)//d o i
{
	int count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstring("-2147483648");
	}
	if(n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
	{
		count += ft_putchar(n + '0');
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)//u
{
	int count;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_unsigned(n / 10);
		count += ft_putnbr_unsigned(n % 10);
	}
	else
	{
		count += ft_putchar(n + '0');
	}
	return (count);
}

int	ft_putnbr16(unsigned int n, int uppercase)//x o X
{
	char *hex_digits;
	int count;

	count = 0;
	if (uppercase == 1)
	{
		hex_digits = "0123456789ABCDEF";
	}
	else
	{
		hex_digits = "0123456789abcdef";
	}
	if (n >= 16)
	{
		count += ft_putnbr16(n / 16, uppercase);
		count += ft_putnbr16(n % 16, uppercase);
	}
	else
	{
		count += ft_putchar(hex_digits[n]);
	}
	return (count);
}

int ft_putptr(void *ptr)//p
{
	unsigned long long address = (unsigned long long)ptr;
	int	count;

	count = 0;
	count += ft_putstring("0x");
	count += ft_putnbr16(address, 0);
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
			if (format[i] == 'c')
			{
				count += ft_putchar(va_arg(args, int));
			}
			else if (format[i] == 's')
			{
				count += ft_putstring(va_arg(args, char *));
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				count += ft_putnbr(va_arg(args, int));
			}
			else if (format[i] == 'u')
			{
				count += ft_putnbr_unsigned(va_arg(args, unsigned int));
			}
			else if (format[i] == 'x')
			{
				count += ft_putnbr16(va_arg(args, unsigned int), 0);
			}
			else if (format[i] == 'X')
			{
				count += ft_putnbr16(va_arg(args, unsigned int), 1);
			}
			else if (format[i] == 'p')
			{
				count += ft_putptr(va_arg(args, void *));
			}
			else if (format[i] == '%')
			{
				count += ft_putchar('%');
				count++;
			}
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
	count = ft_printf("Formato d:%d", 7);
	printf("\n");
	count2 = printf("Formato d:%d", 7);
	printf("\n");
	printf("%d\n", count);
	printf("%d\n", count2);
	free(ptr);

	//%s
	count3 = ft_printf("Formato s:%s", "Hola");
	printf("\n");
	count4 = printf("Formato s:%s", "Hola");
	printf("\n");
	printf("%d\n", count3);
	printf("%d\n", count4);
	return (0);
}
