#include <stdio.h>

/**
 * _memset - function to set memory
 * @s: the pointer to the address to set
 * @c: the character to set the address to
 * @start: the starting index
 * @n: the length of values to set
 *
 * Return: a pointer to the new address
 */
char *_memset(char *s, char c, unsigned int start, unsigned int n)
{
	unsigned int i = start;

	if (s == NULL)
	{
		return (NULL);
	}

	while (i < n + start)
	{
		*(s + i) = c;
		i++;
	}

	return (s);
}
