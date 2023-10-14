#include "shell.h"

/**
 * _printf - this is my own custome defined printf function that
 * prints to the standard output, it handles, %c and %s only for
 * the sake of simplicity, I would be implementing this in my shell.
 * @format: this represents the format specifier for the chars to be
 * printed.
 * Return: number of chars printed successfully.
 */

int _printf(const char *format, ...);

int _printf(const char *format, ...)
{
	int fmt_idx;

	int printed_chars = 0;

	va_list fmt_spec_args;

	va_start(fmt_spec_args, format);

	if (format == NULL)
	{
		return (-1);
	}

	for (fmt_idx = 0; format[fmt_idx] != '\0'; fmt_idx++)
	{
		if (format[fmt_idx] == '%')
		{
			fmt_idx += 1;

			if (format[fmt_idx] == '%')
			{
				_putchar('%');
				printed_chars += 1;
			}
			else if (format[fmt_idx] == 'c')
			{
				char chr_val = va_arg(fmt_spec_args, int);

				if (chr_val)
				{
					_putchar(chr_val);
					printed_chars += 1;
				}
				else
				{
					exit(-1);
				}
			}
			else if (format[fmt_idx] == 's')
			{
				char *str_val = va_arg(fmt_spec_args, char *);

				int str_idx = 0;

				int str_len = 0;

				for (str_idx = 0; str_val[str_idx] != '\0'; str_idx++)
				{
					_putchar(str_val[str_idx]);
				}

				while (*str_val != '\0')
				{
					str_len += 1;

					str_val += 1;
				}

				printed_chars += str_len;
			}
		}
		else /*No format specifier was found*/
		{
			_putchar(format[fmt_idx]);
			printed_chars += 1;
		}
	}

	va_end(fmt_spec_args);

	return (printed_chars);
}

