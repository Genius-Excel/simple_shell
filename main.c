#include "shell.h"

/**
 * main - this is the main function for my shell program.
 * Return: 0 on sucess.
 */

int main(void);

int main(void)
{
	bool interactive_shell;

	char *get_line_val;

	char **cmd_args;

	char *token;

	int arg_idx;

	char *usr_prmpt = "(Genius Excel)$ ";

	interactive_shell = isatty(fileno(stdin));


	while (1)
	{

		/*check for interactive shell mode*/
		if (interactive_shell)
		{
			_printf("%s", usr_prmpt);

			fflush(stdout);

			get_line_val = cstm_getline();

			if (get_line_val == NULL)
			{
				break; /*Exit interactive mode*/
			}

			/*printf("(Favour Shell)%s$ ", currt_wrk_dir); */
		}
		else /*Indicates shell is in non-interactive mode*/
		{
			get_line_val = cstm_non_interactive_getline();

			if (get_line_val == NULL) /*Exit non-interactive mode*/
			{
				/*Close file and exit the non-interacitve mode*/

				break; /*Switche to interactive shell mode*/
			}
		}

		/*Check if multiple commands were enetered*/
		if (strstr(get_line_val, ";") != NULL)
		{
			/*			cmd_seperator(get_line_val, currt_wrk_dir, usr_prmpt);*/

			free(get_line_val);
			continue;
		}
		/*Dynamically Allocate memory for the arguments to be executed*/
		cmd_args = malloc(sizeof(char *) * (MAX_ARGS + 1));

		if (cmd_args == NULL)
		{
			perror("Failed to Allocate Memory");
			exit(EXIT_FAILURE);
		}


		arg_idx = 0;

		token = cstm_strtok(get_line_val, " \t\r\n\a");

		while (token != NULL && arg_idx < MAX_ARGS)
		{
			cmd_args[arg_idx] = token;

			arg_idx++;

			token = cstm_strtok(NULL, " \t\r\n\a");
		}

		cmd_args[arg_idx] = NULL;

		if (arg_idx == 0)
		{
			free(get_line_val);
			free(cmd_args);

			continue;
		}

		execute_builtin_command(cmd_args, get_line_val);

		free(get_line_val);
		free(cmd_args);

		if (!interactive_shell)
		{
			break;
		}
	}

	return (0);
}
