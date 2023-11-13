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
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(arguments_list, int);
				block_print += print_number(num);
			}
		}
		format++;
	}

	va_end(arguments_list);
	return block_print;
}

int print_number(int n)
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
	{
		count += print_number(n / 10);
	}

	digit = n % 10 + '0';
	write(1, &digit, 1);
	return count + 1;
}
