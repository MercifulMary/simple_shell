#include <stdio.h>
#include <unistd.h>
#include "lib.h"

/**
 * _puts - function to write to screen
 * @out: the standard output
 * @s: the string
 *
 * Return: the length of the string
 */
int _puts(int out, char *s)
{
	int i = 0;

	if (s !=  NULL)
	{
		while (*(s + i) != '\0')
		{
			if (_putchar(out, *(s + i)) == -1)
			{
				return (-1);
			}
			i++;
		}
	}

	return (i);
}

/**
 * _putchar - writes to io
 * @fd: the file descriptor
 * @c: the character
 *
 * Return: int
 */
int _putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}
