#include "main.h"

/**
*_printf - printf function
*@format: Format string with placeholders
*@...: Variable number of arguments
*
*Return: Number of characters printed (excluding null byte)
*/
int _printf(const char *format, ...)
{
if (format == NULL)
return -1;

int block_print = 0;
va_list arguments_list;
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

switch (*format)
{
case '%':
write(1, format, 1);
block_print++;
break;
case 'c':
block_print += print_char(arguments_list);
break;
case 's':
block_print += print_str(arguments_list);
break;
case 'd':
case 'i':
block_print += print_number(arguments_list);
break;
default:
write(1, "%", 1); // Print '%' if an unsupported specifier is encountered
block_print++;
break;
}
}
format++;
}

va_end(arguments_list);
return block_print;
}

/**
*print_char - Prints a character
*@arguments_list: Arguments list
*
*Return: Number of characters printed
*/
int print_char(va_list arguments_list)
{
char c = va_arg(arguments_list, int);
write(1, &c, 1);
return 1;
}

/**
*print_str - Prints a string
*@arguments_list: Arguments list
*
*Return: Number of characters printed
*/
int print_str(va_list arguments_list)
{
char *str = va_arg(arguments_list, char *);
if (str == NULL)
str = "(null)";

int str_len = 0;
while (str[str_len] != '\0')
str_len++;

write(1, str, str_len);
return str_len;
}

/**
*print_number - Prints an integer
*@arguments_list: Arguments list
*
*Return: Number of characters printed
*/
int print_number(va_list arguments_list)
{
int num = va_arg(arguments_list, int);
return print_number_recursive(num);
}

/**
*print_number_recursive - Recursively prints the digits of an integer
*@n: Integer to be printed
*
*Return: Number of characters printed
*/
int print_number_recursive(int n)
{
int count = 0;
char digit;

if (n < 0)
{
write(1, "-", 1);
n = -n;
count++;
}

if (n / 10)
count += print_number_recursive(n / 10);

digit = n % 10 + '0';
write(1, &digit, 1);

return count + 1;
}
