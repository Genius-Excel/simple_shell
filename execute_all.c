#include "shell.h"

/**
* execute_builtin_command - this function handles every logic
* it checks for buitin commands and calls the executor function.
* @cmd_args: this is the command arguments to be checked.
*
* Return: void
*/

void execute_builtin_command(char **cmd_args);

void execute_builtin_command(char **cmd_args)
{
	char executable_file[MAX_INPUT_SIZE];

	char *file_path = "/bin/";

	if (strcmp(cmd_args[0], "env") == 0)
	{
		char **env;

		for (env = environ; *env != NULL; env++)
		{
			_printf("%s\n", *env);
		}
	}
	else if (strcmp(cmd_args[0], "setenv") == 0)
	{
		/*Logic to be implemented*/
	}
	else if (strcmp(cmd_args[0], "unsetenv") == 0)
	{
		/*Logic to be implemented*/
	}
	else if (strcmp(cmd_args[0], "cd") == 0)
	{
		/*Logic to be implemented*/
	}
	else if (strcmp(cmd_args[0], "#") == 0)
	{
		/* This is a comment, do nothing*/
	}
	else
	{
		if (strchr(cmd_args[0], '/') != NULL) /*USer entered full path*/
		{
			if (access(cmd_args[0], X_OK) != -1)
			{
				call_and_execute(cmd_args);
			}
			else
			{
				int n = 1;

				char *ms = "./hsh: %d: %s: not found\n";

				_fprintf(stderr, ms, n, cmd_args[0]);
				exit(127);
			}
		}
		else /*User entered the file name*/
		{
			strcpy(executable_file, file_path);
			strcat(executable_file, cmd_args[0]);

			if (access(executable_file, X_OK) != -1)
			{
				call_and_execute(cmd_args);
			}
			else
			{
				char *ms = "./hsh: %d: %s: not found\n";

				_fprintf(stderr, ms, 1, cmd_args[0]);
				exit(127);
			}
		}
	}
}
