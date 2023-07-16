#include <stdio.h>
#include "lib.h"

/**
 * print_commands - function to print commands
 * @clist: the command list
 * @csize: the size of the command list
 */
void print_commands(char **clist, long csize)
{
	long i = 0;

	_puts(1, "Array list:\n");
	while (i <= csize)
	{
		if (clist != NULL)
		{
			_puts(1, ":");
			if (clist[i] == NULL)
			{
				_puts(1, "****empty");
			}
			else
			{
				_puts(1, clist[i]);
			}
			_puts(1, "\n");
			i++;
		}
	}
}
