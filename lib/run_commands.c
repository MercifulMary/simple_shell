#include <stdio.h>
#include "lib.h"

/**
 * run_commands - function to run commands
 * @clist: the command list
 * @csize: the size of the command list
 * @env: the address of the environment variables
 *
 * Return: 1
 */
int run_commands(char ***clist, long csize, char ***env)
{
	if (append_path(clist, csize) == -1)
	{
		return (-1);
	}

	return (run(*clist, env));
}
