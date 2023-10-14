#include "shell.h"

/**
* change_dir - this function is an helper function that handles
* all the cd command implemtations in the shell program.
* @cmd_args: command lin arguments to be executed.
* @currt_wrk_dir: current working directory of the enviroment.
* Return: void
*/

void change_dir(char *cmd_args[], char *currt_wrk_dir)
{
	int arg_idx = 1;

	char *prev_wk_dir;

	if (cmd_args[arg_idx] == NULL)
	{
		chdir(cstm_getenv("HOME"));
	}
	else if (strcmp(cmd_args[arg_idx], "-") == 0)
	{
		prev_wk_dir = cstm_getenv("OLDPWD");

		if (prev_wk_dir != NULL)
		{
			if (chdir(prev_wk_dir) == -1)
			{
				perror("cd");
			}
		}
		else
		{
			_printf("bash: cd: OLDPWD not set\n");
		}
	}
	else
	{
		if (chdir(cmd_args[arg_idx]) == -1)
		{
			perror("cd");
		}
	}

	getcwd(currt_wrk_dir, sizeof(currt_wrk_dir));
}
