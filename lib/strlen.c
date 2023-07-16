#include <stdio.h>

/**
 * _strlen - gets the length of a strings
 * @s: string
 *
 * Return: an int
 */
int _strlen(char *s)
{
	unsigned int i = 0;

	if (s == NULL)
	{
		return (0);
	}

	while (*(s + i) != '\0')
	{
		i++;
	}

	return (i);
}
