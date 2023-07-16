#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
 * array_copy - function to copy an array to another
 * @dest: the array to be copied into
 * @src: the array to copy from
 * @size: the size of the array
 * @start: start from
 * @end: end at
 *
 * Return: 1
 *
 */
int array_copy(char ***dest, char ***src, long size, int start, int end)
{
	int i = 0;
	int width = end - start + 2;
	int len = 0;

	if (start > end)
	{
		return (-1);
	}

	if (*dest == NULL)
	{
		*dest = calloc(width, sizeof(char *));
		if (*dest == NULL)
		{
			return (-1);
		}

	}
	else
	{
		*dest = reallocarray(*dest, width, sizeof(char *));
		if (*dest == NULL)
		{
			free_array(dest, size);
			return (-1);
		}
	}

	for (i = 0; i < width - 1; i++)
	{
		*(*dest + i) = _strcpy(*(*dest + i), *(*src + i + start));
		if (*(*dest + i) == NULL)
		{
			free_array(dest, width);
			return (-1);
		}
		len++;
	}
	*(*dest + width - 1) = NULL;
	return (len);
}
