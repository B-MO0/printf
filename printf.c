#include "main.h"

int _printf(const char *format, ...)
{
int block_print = 0;
va_list arguments_list;

if (format == NULL)
{
return (-1);
}

va_start(arguments_list, format);

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
char c = va_arg(arguments_list, int);
write(1, &c, 1);
block_print++;
}
else if (*format == 's')
{
char *str = va_arg(arguments_list, char *);
int str_len = 0;
while (str[str_len] != '\0')
str_len++;
write(1, str, str_len);
block_print += str_len;
}
}
format++;
}

va_end(arguments_list);
return block_print;
}
