#include "main.h"
#include <string.h>

int _putchar(char c);
int print_number(int n);

/**
*_printf - printf function
*@format: Format string
*@...: Variable number of arguments
*
*Return: Number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
if (format == NULL)
return (-1);
int block_print = 0;
va_list arguments_list;
va_start(arguments_list, format);
while (*format)
{
if (*format != '%')
{
_putchar(*format);
block_print++;
}
else
{
format++;
if (*format == '\0')
break;
if (*format == '%' || *format == 'c')
{
_putchar(*format);
block_print++;
}
else if (*format == 's')
{
char *str = va_arg(arguments_list, char *);
int str_len = strlen(str);
write(1, str, str_len);
block_print += str_len;
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(arguments_list, int);
block_print += print_number(num);
}
}
format++;
}
va_end(arguments_list);
return (block_print);
}
/**
*print_number - Prints an integer
*@n: Integer to be printed
*
*Return: Number of characters printed
*/
int print_number(int n)
{
int count = 0;
if (n < 0)
{
_putchar('-');
n = -n;
count++;
}
if (n >= 10)
count += print_number(n / 10);
_putchar((n % 10) + '0');
return (count + 1);
}

/**
*_putchar - Writes a character to standard output
*@c: Character to be written
*
*Return: On success, returns the character written; On error, returns -1
*/
int _putchar(char c)
{
return (write(1, &c, 1));
}
