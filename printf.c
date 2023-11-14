#include "main.h"

/**
*_printf - Custom printf function
*@format: Format string with placeholders
*
*Return: Number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
int block_print = 0;
va_list args_list;

if (format == NULL)
return (-1);

va_start(args_list, format);

while (*format)
{
if (*format != '%')
{
write(1, format, 1);
block_print++;
}
else
{
format++;

if (*format == '\0')
break;

if (*format == '%')
{
write(1, format, 1);
block_print++;
}
else if (*format == 'c')
{
char c = va_arg(args_list, int);
write(1, &c, 1);
block_print++;
}
else if (*format == 's')
{
char *str = va_arg(args_list, char *);
int str_len = 0;

while (str[str_len] != '\0')
str_len++;

write(1, str, str_len);
block_print += str_len;
}
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args_list, int);
block_print += print_number(num);
}
}
format++;
}

va_end(args_list);
return (block_print);
}
