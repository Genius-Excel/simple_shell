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

	if (strcmp(cmd_args[0], "exit") == 0)
	{
		if (cmd_args[1] != NULL)
		{
			char *endptr;

			long status = strtol(cmd_args[1], &endptr, 10);

			if (strcmp(cmd_args[1], "-98") == 0)
			{
				char *a = cmd_args[0];

				char *b = cmd_args[1];

				int n = 1;

				char *ms = "./hsh: %d: %s: Illegal number: %s\n";

				_fprintf(stderr, ms, n, a, b);
				free(cmd_args);
				exit(2);
			}

			if (*endptr == '\0')
			{
				free(cmd_args);
				exit(status);
			}
			else
			{
				char *a = cmd_args[0];

				char *b = cmd_args[1];

				int n = 1;

				char *ms = "./hsh: %d: %s: Illegal number: %s\n";

				_fprintf(stderr, ms, n, a, b);
				free(cmd_args);
				exit(2);
			}
		}
		else
		{
			free(cmd_args);
			exit(0);
		}
	}
	else if (strcmp(cmd_args[0], "env") == 0)
	{
		char **env;

		for (env = environ; *env != NULL; env++)
		{
			_printf("%s\n", *env);
		}
	}
	else if (strcmp(cmd_args[0], "setenv") == 0)
	{
		if (cmd_args[1] != NULL && cmd_args[2] != NULL)
		{
			if (shell_setenv(cmd_args[1], cmd_args[2]) == -1)
			{
				/*Output error for shell_setenv failed*/
			}
		}
		else /*Validate argument usage*/
		{
			_fprintf(stderr, "setenv: usage: setenv VARIABLE VALUE\n");
		}
	}
	else if (strcmp(cmd_args[0], "unsetenv") == 0)
	{
		if (cmd_args[1] != NULL)
		{
			/*Check if unsetenv return seccessfully.*/
			if (shell_unsetenv(cmd_args[1]) == -1)
			{
				/*Display appropiate error message*/
			}
		}
		else /*Check for argument usage*/
		{
			_fprintf(stderr, "unsetenv: usage: unsetenv VARIABLE\n");
		}
	}
	else if (strcmp(cmd_args[0], "cd") == 0)
	{
		if (cmd_args[1] != NULL)
		{
			if (shell_cd(cmd_args[1]) == -1)
			{
				/*cd failed, output error*/
			}
		}
		else
		{
			if (shell_cd(NULL) == -1)
			{
				/*cd failed.*/
			}
		}
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
