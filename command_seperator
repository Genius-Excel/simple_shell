#include "shell.h"

/**
* cmd_seperator - this function handles the logic of command seperators
* @get_line_val: this the text read from standard input to be tokenized.
* @currt_wrk_dir: this is the current working directory of the shell.
* @user_prompt: this is the user prompt for the shell.
* Return: void
*/

void cmd_seperator(char *get_line_val, char *currt_wrk_dir, char *user_prompt);

void cmd_seperator(char *get_line_val, char *currt_wrk_dir, char *user_prompt)
{

	int arg_idx = 0;

	char *token;

	char *cmd;

	char **cmd_args;

	int ln = 0;

	(void)user_prompt;

	token = cstm_strtok(get_line_val, ";");

	while (token != NULL && arg_idx < MAX_ARGS)
	{
		cmd = token;

		/*Check number of commands entered seprated by space or tab*/
		while (*cmd == ' ' || *cmd == '\t')
		{
			/*Increament the number of commands count*/

			cmd += 1;
		}

		ln = strlen(cmd);

		while (ln > 0 && (cmd[ln - 1] == ' ' || cmd[ln - 1] == '\t'))
		{
			ln -= 1;
		}
		cmd[ln] = '\0'; /*I null terminated the command array*/

	/*Allocate memory for the command line arguments and execute*/

		cmd_args = malloc(sizeof(char *) * (MAX_ARGS + 1));

		if (cmd_args == NULL)
		{
			perror("Memory Allocation Failed");
			exit(EXIT_FAILURE);
		}

		arg_idx = 0; /*I update the value of index to 0*/

		token = cstm_strtok(cmd, " \t\n");

		while (token != NULL && arg_idx < MAX_ARGS)
		{
			/*Populate the allocated memory*/
			cmd_args[arg_idx] = token;

			token++;

			token = cstm_strtok(NULL, " \t\n");
		}
		cmd_args[arg_idx] = NULL; /*Null terminate the array*/

		if (arg_idx > 0)
		{
			if (strcmp(cmd_args[0], "exit") == 0)
			{
				free(cmd_args);
				exit(EXIT_SUCCESS);
			}
			else if (strcmp(cmd_args[0], "env") == 0)
			{
				char **env;

				for (env = environ; *env != NULL; env++)
				{
					_printf("%s\n", *env);
				}
			}
			else if (strcmp(cmd_args[0], "cd") == 0)
			{
				change_dir(cmd_args, currt_wrk_dir);
			}
			else
			{

			/*Validate executable file before calling execve*/
				if (strchr(cmd_args[0], '/') != NULL)
				{
					if (access(cmd_args[0], X_OK) != -1)
					{
						call_and_execute(cmd_args);
					}
					else
					{
						_printf("bash: %s: No such file or directory\n", cmd_args[0]);
					}
				}
				else /*USer enterd the file name*/
				{
					char *file_path = "/bin/";

					char exec_file[MAX_INPUT_SIZE];

					strcpy(exec_file, file_path);
					strcat(exec_file, cmd_args[0]);
					if (access(exec_file, X_OK) != -1)
					{
						call_and_execute(cmd_args);
					}
					else
					{
						_printf("bash: %s: No such file or directory", exec_file);
					}
				}
			}
		}
	/*End of (if arg_idx > 0)*/
		free(cmd_args);

		token = cstm_strtok(NULL, ";");
	}
/*End of while loop*/

}
