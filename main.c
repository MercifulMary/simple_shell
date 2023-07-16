#include <stdio.h>
#include "main.h"
#include "lib/lib.h"
#include "lib/getline.c"
#include "lib/strcmp.c"
#include "lib/strncmp.c"
#include "lib/strlen.c"
#include "lib/strcpy.c"
#include "lib/strtok.c"
#include "lib/strcat.c"
#include "lib/run_commands.c"
#include "lib/append_path.c"
#include "lib/run.c"
#include "lib/free_array.c"
#include "lib/array_copy.c"
#include "lib/print_env.c"
#include "lib/puts.c"
#include "lib/print_commands.c"

void exec(char **arr, int size, char ***);
void non_interactive_mode(char ***, long *, char ***, int, char ***);
void run_interactive_mode(char ***, long *, char ***);
int exec_run_commands(char ***, char ***);

/**
 * main - entry point
 * @ac: argument count
 * @av: argument list
 * @env: the environment variables
 *
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	char **clist = NULL;
	long csize = 0;
	char *line = NULL;

	if (isatty(STDIN_FILENO))
	{
		if (ac == 1)
		{
			run_interactive_mode(&clist, &csize, &env);
		}
		else if (ac == 0 || av == NULL)
		{
			_puts(2, "Error: too few arguments supplied\n");
		}
		else
		{
			non_interactive_mode(&clist, &csize, &env, ac, &av);
		}
	}
	else
	{
		line = _getline();

		if (ac == 1 && (*line != '\0'))
		{
			csize = _strtok(&clist, line, "\n");
			exec(clist, csize, &env);
		}
		else if (ac > 1)
		{
			non_interactive_mode(&clist, &csize, &env, ac, &av);
		}
		else
		{
			_puts(2, "Error: too few arguments supplied\n");
		}
	}

	free(line);
	free_array(&clist, csize + 1);
	return (0);
}

/**
 * exec - executes command
 * @arr: an array of commands
 * @size: the size of the array
 * @env: the address of the environment variables
 */
void exec(char **arr, int size, char ***env)
{
	int i = 0;
	long csize = 0;
	char **clist = NULL;

	for (i = 0; i < size; i++)
	{
		if (clist != NULL)
		{
			free_array(&clist, csize + 1);
			clist = NULL;
		}
		if (arr[i] != NULL)
		{
			csize = _strtok(&clist, arr[i], " ");
			if (csize > 0)
			{
				exec_run_commands(&clist, env);
			}
		}
	}
	free_array(&clist, csize + 1);
}

/**
 * non_interactive_mode - function to run in interactive mode
 * @clist: the command list
 * @csize: the command size
 * @env: the address of the environment variables
 * @ac: the argument count
 * @av: the argument list
 */
void non_interactive_mode(
		char ***clist, long *csize, char ***env, int ac, char ***av)
{
	*csize = array_copy(clist, av, ac, 1, ac - 1);

	if (*csize != -1)
	{
		exec_run_commands(clist, env);
	}
	else
	{
		_puts(2, "Error(array_copy)\n");
	}
}

/**
 * run_interactive_mode - function to run in interactive mode
 * @clist: the command list
 * @csize: the command size
 * @env: the address of the environment variables
 */
void run_interactive_mode(char ***clist, long *csize, char ***env)
{
	char *line = NULL;
	int open = 1;

	while (open)
	{
		_puts(1, "$ ");
		line = _getline();
		fflush(stdout);

		if (*line == EOF)
		{
			open = 0;
			free(line);
			_puts(1, "\n");
			continue;
		}
		else if (*line == '\0')
		{
			free(line);
			continue;
		}

		if (*clist != NULL)
		{
			free_array(clist, *csize + 1);
			*clist = NULL;
		}

		*csize = _strtok(clist, line, " ");
		free(line);
		if (*csize > 0)
		{
			if (exec_run_commands(clist, env) == 0)
			{
				open = 0;
				continue;
			}
		}
	}
}

/**
 * exec_run_commands - function to execute run_commands
 * @clist: the command list
 * @env: the address of the environment variables
 *
 * Return: status
 */
int exec_run_commands(char ***clist, char ***env)
{
	if (clist == NULL)
	{
		_puts(2, "Error: Unable to split command list\n");
	}
	else
	{
		if (_strcmp("exit", (*clist)[0]) == 0)
		{
			free_array(clist, 2);
			exit(EXIT_SUCCESS);
			return (0);
		}

		run(*clist, env);
	}

	return (1);
}
