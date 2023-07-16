#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
 * _print_env - print environment variables
 * @env: the environment variable address
 */
void _print_env(char ***env)
{
	int i = 0;

	if (*env != NULL)
	{
		while ((*env)[i] != NULL)
		{
			_puts(1, (*env)[i]);
			_puts(1, "\n");
			i++;
		}
	}
}

/**
 * _set_env - sets environment variables
 * @var: the environment variable to add
 * @env: the environment variable address
 *
 * Return: 1 if successful
 */
int _set_env(char *var, char ***env)
{
	char *name = NULL;
	int i = 0;
	int count;
	char **arr;

	arr = malloc(sizeof(char *) * 3);
	if (arr == NULL)
		return (-1);

	count = _strtok(&arr, var, "=");
	if (count != 2)
		return (-1);
	name = _strcpy(name, arr[0]);
	if (*env != NULL)
	{
		while (((*env)[i]) != NULL)
		{
			count = _strtok(&arr, (*env)[i], "=");
			if (count == 2 && _strcmp(arr[0], name) == 0)
			{
				(*env)[i] = var;
				return (1);
			}
			i++;
		}

		(*env)[i] = var;
		(*env)[i + 1] = NULL;

		free(name);
		free_array(&arr, 3);

		return (1);
	}
	return (0);
}

/**
 * _unset_env - unsets environment variables
 * @name: the environment variable to add
 * @env: the environment variable address
 *
 * Return: 1 if successful
 */
int _unset_env(char *name, char ***env)
{
	int i = 0;
	int pos = -1;
	int count;
	char **arr;

	arr = malloc(sizeof(char *) * 3);
	if (arr == NULL)
		return (-1);

	if (*env != NULL)
	{
		while (((*env)[i]) != NULL)
		{
			count = _strtok(&arr, (*env)[i], "=");
			if (pos == -1 && count == 2 && _strcmp(arr[0], name) == 0)
			{
				pos = i;
			}
			i++;
		}

		if (pos == -1)
			return (-1);

		(*env)[pos] = (*env)[i - 1];
		(*env)[i - 1] = NULL;

		free(name);
		free_array(&arr, 3);
		return (1);
	}
	return (0);
}
