#include "shell.h"

/**
* cstm_non_interactive_getline - this is the custom getline function for..
* .. the non-interactive shell, it works like the traditional getline but uses
* the read function to get the input from the file stream.
* Return: On succes, it returns the pointer to the array of characters
* read from the filestream.
*/
char *cstm_non_interactive_getline(void);

char *cstm_non_interactive_getline(void)
{
	ssize_t num_read_val;

	char *buffer_ptr;

	char *mem_ptr;

/*	size_t buffer_ptr_len = 0;*/

	int idx = 0;

	int maximum_size = 1024;

	char c;

	buffer_ptr = malloc(maximum_size * sizeof(char));

	if (buffer_ptr == NULL)
	{
		perror("Failed to allocate memory");

		exit(1);
	}

	while ((num_read_val = read(STDIN_FILENO, &c, 1)) > 0)
	{
		if (c == EOF || c == '\n')
		{
			/*Stops the loop*/
			break;
		}

		buffer_ptr[idx++] = c; /*Populate the allocated memory with c*/


		/*Check if memory allocated is enough*/
		if (idx >= (maximum_size - 1))
		{
			maximum_size += 1024;

			mem_ptr = realloc(buffer_ptr, maximum_size);

			if (mem_ptr == NULL)
			{
				perror("Reallocation of memory failed");

				free(buffer_ptr); /*free alloc mem*/

				exit(1);
			}
			/*Memory Reallocation successful update bfr_ptr*/

			buffer_ptr = mem_ptr;
		}
	}


	if (num_read_val == -1) /*read failed*/
	{
		perror("Read failed");
		free(buffer_ptr); /*Free allocated mem*/
		exit(1);
	}


	/*Check if no characters were read*/
	if (num_read_val == 0)
	{
		free(buffer_ptr);

		exit(1);
	}

	/*Null terminat the buffer*/
	buffer_ptr[idx] = '\0';

	return (buffer_ptr);
}
