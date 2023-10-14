#include "shell.h"

/**
* cstm_getline - this is a custom getline function taht reads input
* from the terminal and returns the array of characters read.
* It works typically like the traditional getline function.
* Return: this function returns the array of read strings on success.
*/

char *cstm_getline(void)
{
	ssize_t getline_re_val;

	char *buffer_ptr = NULL;

	size_t buffer_ptr_len = 0;


	getline_re_val = getline(&buffer_ptr, &buffer_ptr_len, stdin);

	if (getline_re_val == -1)
	{
		/*Check the condition of the end of file*/

		if (feof(stdin))
		{
			_putchar('\n');
			free(buffer_ptr);
			exit(EXIT_SUCCESS);
		}
		else /*This indicates an error cause it's not end of file*/
		{
			free(buffer_ptr);
			perror("Getline Failed");
			exit(EXIT_FAILURE);
		}
	}

	/*Control reads to this point indicate no errors encountered.*/

	return (buffer_ptr);
}
