#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
 * append_path - function to append /bin/
 * @cmd: the command as an array
 * @size: the size of the array
 *
 * Return: 1
 *
 */
int append_path(char ***cmd, long size)
{
	char *path = "/bin/";
	int i = 0;
	int append = 1;

	if (cmd == NULL)
		return (-1);

	while (i < size)
	{
		if ((
			(_strcmp(*(*cmd + i), "|") == 0) ||
			(_strcmp(*(*cmd + i), "&") == 0) ||
			(_strcmp(*(*cmd + i), "||") == 0) ||
			(_strcmp(*(*cmd + i), "&&") == 0)
		) && i < size - 1 && i != 0 && append == 0)
		{
			append = 1;
			i++;
			continue;
		}

		if (append)
		{
			if (_strncmp(path, *(*cmd + i), 5) != 0)
			{
				*(*cmd + i) = _strcat(path, *(*cmd + i));
				if (*(*cmd + i) == NULL)
				{
					return (-1);
				}
			}
			append = 0;
		}

		i++;
	}

	return (1);
}
