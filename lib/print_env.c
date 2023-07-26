#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void clear_array(char ***arr, int size);

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

	if (*env != NULL)
	{
		arr = malloc(sizeof(char *) * 3);
		if (arr == NULL)
			return (-1);

		count = _strtok(&arr, var, "=");
		if (count != 2)
		{
			free_array(&arr, 0);
			return (-1);
		}
		name = _strcpy(name, arr[0]);
		clear_array(&arr, 3);

		while (((*env)[i]) != NULL)
		{
			count = _strtok(&arr, (*env)[i], "=");
			if (count == 2 && _strcmp(arr[0], name) == 0)
			{
				(*env)[i] = _strcpy((*env)[i], var);
				free(name);
				free_array(&arr, 0);
				return (1);
			}
			else
			{
				free_array(&arr, 0);
				arr = NULL;
			}
			i++;
		}

		(*env)[i] = _strcpy((*env)[i], var);
		(*env)[i + 1] = NULL;

		free(name);
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

	if (*env != NULL)
	{
		arr = malloc(sizeof(char *) * 3);
		if (arr == NULL)
			return (-1);

		while (((*env)[i]) != NULL)
		{
			count = _strtok(&arr, (*env)[i], "=");
			if (pos == -1 && count == 2 && _strcmp(arr[0], name) == 0)
			{
				pos = i;
			}
			free_array(&arr, 0);
			arr = NULL;
			i++;
		}

		if (pos == -1)
		{
			free_array(&arr, 0);
			return (-1);
		}

		(*env)[pos] = (*env)[i - 1];
		(*env)[i - 1] = NULL;

		free_array(&arr, 0);
		return (1);
	}
	return (0);
}

/**
 * clear_array - function to clear array content
 * @arr: the address of the array
 * @size: the size to clear up to
 */
void clear_array(char ***arr, int size)
{
	int i = 0;

	if (*arr != NULL)
	{
		for (i = 0; i < size; i++)
		{
			free((*(arr))[i]);
		}
	}
}
