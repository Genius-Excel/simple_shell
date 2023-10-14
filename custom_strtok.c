#include "shell.h"

/**
* cstm_strtok - this is a custom function that tokenizes a string
* it works based on the delimiter of the string to be tokenized.
* @str: string to be tokenized which is the first argument.
* @delim: this represents the delimiter ofthe string in what pattern
* to be splitted.
* Return: tokenized string on success, else NULL.
*/

char *cstm_strtok(char *str, const char *delim);

char *cstm_strtok(char *str, const char *delim)
{
	static char *next_token;

	char *new_token;

	if (str != NULL)
	{
		/*Updates the next value of the string*/
		next_token = str;
	}

	/*Check for the end of tokens in the string*/
	if (next_token == NULL || *next_token == '\0')
	{
		/*End of the string null is returned*/
		return (NULL);
	}

	while (*next_token != '\0' && strchr(delim, *next_token) != NULL)
	{
		next_token++;
	}

	/*check for end of tokens*/

	if (*next_token == '\0')
	{
		return (NULL);
	}

	new_token = next_token;

	while (*next_token != '\0' && strchr(delim, *next_token) == NULL)
	{
		next_token += 1;
	}

	if (*next_token != '\0')
	{
		*next_token = '\0';

		next_token += 1;
	}

	/*All strings has been tokenized completely */
	return (new_token);
}
