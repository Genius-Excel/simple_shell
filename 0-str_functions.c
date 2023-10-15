#include "shell.h"


/**
* _putchar - this function prints a character to the standard output.
* @c: character to be printed.
* Return: the printed character to stdout.
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}


