#include "shell.h"

int shell_cd(const char *directory)
{
	char *current_dir;

	current_dir = getcwd(NULL, 0);

	if (directory == NULL)
	{
		/* Change to the user's home directory if no argument is given*/
		directory = getenv("HOME");
		if (directory == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return -1;
		}
	}
	else if (strcmp(directory, "-") == 0)
	{
		/* Handle "cd -" to go back to the previous directory*/
		directory = getenv("OLDPWD");
		if (directory == NULL)
		{
			fprintf(stderr, "cd: OLDPWD not set\n");
			return -1;
		}
		fprintf(stdout, "%s\n", current_dir);
	}


	if (current_dir == NULL)
	{
		perror("cd");
		return -1;
	}

	if (chdir(directory) != 0)
	{
		perror("cd");
		free(current_dir);
		return -1;
	}

	/* Update the PWD and OLDPWD environment variables*/
	if (setenv("OLDPWD", current_dir, 1) != 0 || setenv("PWD", directory, 1) != 0)
	{
		perror("cd");
		free(current_dir);
		return -1;
	}

	free(current_dir);
	return 0;
}

