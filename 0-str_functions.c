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

/**
* cstm_strncmp - this function comares two strings
* @str1: first strng to be comapred.
* @str2: second sring to be compared.
* @num: byte size to be comapared.
* Return: 0 on success.
*/

int cstm_strncmp(char *str1, char *str2, int num)
{
	int comp = 0;

	int i = 0;

	while ((*str1 != '\0' || *str2 != '\0') && i < num)
	{
		if (*str1 != *str2)
		{
			comp += 1;
		}

		str1 += 1;

		str2 += 1;

		i += 1;
	}

	/*check for valid comparison*/
	if (comp != 0)
	{
		return (-1);
	}

	return (comp);
}
