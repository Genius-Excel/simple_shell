#include "shell.h"

/**
* _putchar - this function prints a single character to the standard
* output.
* @c: character to be printed to stdout
* Return: printed character.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
