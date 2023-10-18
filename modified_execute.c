#include "shell.h"

/**
* call_and_execute - Execute the given command and handle exit status
* @args: Command line arguments to execute
*/

void call_and_execute(char *args[]);

void call_and_execute(char *args[])
{
	pid_t pid_fork_val;
	int wt_status;

	pid_fork_val = fork();

	if (pid_fork_val == -1) /* Potential error in creating a child */
	{
		perror("Fork Error");
		exit(EXIT_FAILURE);
	}

	if (pid_fork_val == 0) /* This indicates the child process */
	{
		/* Condition checks if user entered the full path */
		if (strchr(args[0], '/') != NULL)
		{
			/* Validate the command received before executing */
			if (execve(args[0], args, environ) == -1)
			{
				perror("Error from execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			char *path = cstm_getenv("PATH");
			char *token = cstm_strtok(path, ":");

			while (token != NULL)
			{
				char executable_file[MAX_INPUT_SIZE];

				strcpy(executable_file, token);
				strcat(executable_file, "/");
				strcat(executable_file, args[0]);

				if (access(executable_file, X_OK) != -1)
				{
					execve(executable_file, args, environ);
				}

				token = cstm_strtok(NULL, ":");
			}
			_fprintf(stderr, "./hsh: %d: %s: not found\n", 1, args[0]);
			exit(127);
		}
	}
	else
	{
		wait(&wt_status);
	/*
	*	do {
	*		waitpid(pid_fork_val, &wt_status, 0);

	*		if (WIFEXITED(wt_status))
	*		{
	*			exit(WEXITSTATUS(wt_status));
	*		}
	*		if (WIFSIGNALED(wt_status))
	*		{
	*			raise(WTERMSIG(wt_status));
	*		}
	*	} while (WIFEXITED(wt_status) && WIFSIGNALED(wt_status));
	*/
	}
	
}
