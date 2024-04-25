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

int ft_putchar(char c)//c y %
{
	write(1, &c, sizeof(char) * 1);
	return (c);
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
	return (*str);
}

void	ft_putnbr(int n)//d o i
{
	if (n == -2147483648)
	{
		ft_putstring("-2147483648");
	}
	if(n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

void	ft_putnbr_unsigned(unsigned int n)//u
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
	}
}

void	ft_putnbr16(unsigned int n, int uppercase)//x o X
{
	char *hex_digits;

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
		ft_putnbr16(n / 16, uppercase);
		ft_putnbr16(n % 16, uppercase);
	}
	else
	{
		ft_putchar(hex_digits[n]);
	}
}

void ft_putptr(void *ptr)//p
{
	unsigned long long address = (unsigned long long)ptr;
	ft_putstring("0x");
	ft_putnbr16(address, 0);
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
				ft_putchar(va_arg(args, int));
			}
			else if (format[i] == 's')
			{
				ft_putstring(va_arg(args, char *));
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				ft_putnbr(va_arg(args, int));
			}
			else if (format[i] == 'u')
			{
				ft_putnbr_unsigned(va_arg(args, unsigned int));
			}
			else if (format[i] == 'x')
			{
				ft_putnbr16(va_arg(args, unsigned int), 0);
			}
			else if (format[i] == 'X')
			{
				ft_putnbr16(va_arg(args, unsigned int), 1);
			}
			else if (format[i] == 'p')
			{
				ft_putptr(va_arg(args, void *));
			}
			else if (format[i] == '%')
			{
				ft_putchar('%');
			}
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	int	count;
	int	count2;
	int	*ptr;

	ptr = malloc(5 * sizeof(int));
	count = ft_printf("Esto es una prueba1: %s \n", "hola");
	count2 = printf("Esto es una prueba2: %s \n", "hola");
	printf("%d\n", count);
	printf("%d\n", count2);
	free(ptr);
	return (0);
}
