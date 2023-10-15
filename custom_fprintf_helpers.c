#include "shell.h"

/**
* err_putchar - this function prints a single character to the standard
* error.
* @c: character to be printed to stderr
* Return: printed character.
*/

int err_putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
* print_integer - this function prints and interger with err_putchar.
* @val: integer to be printed.
* Return: void
*/

void print_integer(int val)
{
	int buf_idx = 0;

	int i;

	char buffer[12];

	if (val < 0)
	{
		err_putchar('-');
		val = -(val);
	}

	if (val == 0)
	{
		err_putchar('0');
		return;
	}

	while (val > 0)
	{
		buffer[buf_idx] = '0' + (val % 10);

		val /= 10;

		buf_idx += 1;
	}

	for (i = buf_idx - 1; i >= 0; i--)
	{
		err_putchar(buffer[i]);
	}
}


/**
* _integer_length - this function counts the length of an integer.
* @integer: integer length to be counted.
* Return: lenght of the integer.
*/

int _integer_length(int integer)
{
	int actual_length = 0;

	if (integer == 0)
	{
		return (1);
	}

	if (integer < 0)
	{
		actual_length += 1;
		integer = -(integer);
	}

	do {
		actual_length += 1;
		integer /= 10;
	} while (integer > 0);

	return (actual_length);
}
