#include "shell.h"

int shell_setenv(const char *name, const char *value)
{
    if (name == NULL)
    {
        fprintf(stderr, "setenv: missing variable name\n");
        return -1;
    }

    if (setenv(name, value, 1) != 0)
    {
        perror("setenv");
        return -1;
    }

    return 0;
}

int shell_unsetenv(const char *name)
{
    if (name == NULL)
    {
        fprintf(stderr, "unsetenv: missing variable name\n");
        return -1;
    }

    if (unsetenv(name) != 0)
    {
        perror("unsetenv");
        return -1;
    }

    return 0;
}

