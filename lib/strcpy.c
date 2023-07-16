#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
 * _strcpy - copy a string into another
 * @dest: string 1
 * @src: string 2
 *
 * Return: pointer to the new string
 */
char *_strcpy(char *dest, char *src)
{
	unsigned int i = 0;
	int len = 0;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}

	if (src == NULL)
		return (NULL);

	if (dest == NULL)
	{
		len = _strlen(src);

		dest = malloc(sizeof(char) * (len + 1));
		if (dest == NULL)
		{
			free(dest);
			return (NULL);
		}
	}

	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}

	*(dest + i) = '\0';

	return (dest);
}
