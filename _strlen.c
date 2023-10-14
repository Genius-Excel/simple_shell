#include "shell.h"

/**
* _strlen - this funtion returns the lenght of a string.
* @str: string array to be counted.
* Return: Lenght of the string.
*/

int _strlen(char *str)
{
	int len_counter = 0;

	while (*str != '\0')
	{
		len_counter += 1;

		str += 1;
	}

	return (len_counter);
}
