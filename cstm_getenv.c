#include "shell.h"

/**
* cstm_getenv - this is my custom getenv function that would be used
* to get the current enviroment of my shell.
* @env_name: this represents the enviroment to be gotten as an argument.
* Return: on sucess it returns the environment, else NULL.
*/

char *cstm_getenv(char *env_name)
{
	char **env;

	size_t ln = 0;

	char *ent_env;

	if (env_name == NULL) /*No valid name was found*/
	{
		return (NULL);
	}

	/* Loop through the enviroment variables*/

	for (env = environ; *env != NULL; env++)
	{
		ent_env = *env;

		ln = strlen(env_name);

		if (strncmp(ent_env, env_name, ln) == 0 && ent_env[ln] == '=')
		{
			return (&ent_env[ln + 1]);
		}
	}

	return (NULL);
}
