#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

char *resize(char *b, int size);

/**
 * _getline - Reads input from the user
 *
 * Return: the read input
 */
char *_getline()
{
	int max = 120;
	int ex = 1;
	char *b = NULL;
	long int n, last;
	int limit = sizeof(char) * max;
	int size = limit;

	b = malloc(size * sizeof(char));
	if (b == NULL)
		return (NULL);

	while ((n = read(0, (b + (size - limit)), limit)) > -1)
	{
		last = size - 1;
		if (n == limit && !(*(b + last) == '\n' || *(b + last) == '\0'))
		{
			ex++;
			size = ex * limit;
			b = resize(b, size);
			if (b == NULL)
			{
				return (NULL);
			}
		}
		else
		{
			if (n == 0 || *(b + last - limit + n) != '\n')
			{
				free(b);
				b = malloc(sizeof(char));
				*b = EOF;
			}
			else if (n <= limit && *(b + (last - limit + n)) == '\n')
				*(b + (last - limit + n)) = '\0';
			break;
		}
	}
	return (b);
}

/**
 * resize - function to resize a string
 * @b: the char array
 * @size: the size to resize string to
 *
 * Return: pointer to the newly allocated array
 */
char *resize(char *b, int size)
{
	char *temp = malloc(size * sizeof(char));

	if (temp == NULL)
	{
		free(b);
		return (NULL);
	}

	_strcpy(temp, b);
	free(b);
	b = temp;

	return (b);
}
