#include <stdio.h>

/**
 * _strncmp - compares two strings within a length
 * @s1: string 1
 * @s2: string 2
 * @n: the length to compare
 *
 * Return: an int
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL || n == 0)
		return (0);
	else if (s1 == NULL  && s2 != NULL)
		return (-1);
	else if (s1 != NULL && s2 == NULL)
		return (1);

	while (*(s1 + i) != '\0' && i < n)
	{
		if (*(s1 + i) == *(s2 + i))
		{
			if (i == n - 1)
				return (0);

			i++;
			continue;
		}
		else if ((*(s2 + i) == '\0') || (*(s1 + i) > *(s2 + i)))
		{
			return (1);

		}
		else if (*(s1 + i) < *(s2 + i))
		{
			return (-1);
		}
		i++;
	}

	if (*(s2 + i) != '\0')
	{
		return (-1);
	}

	return (0);
}
