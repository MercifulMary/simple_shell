#include <stdio.h>

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: an int
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	if (s1 == NULL && s2 == NULL)
	{
		return (0);
	}
	else if (s1 == NULL && s2 != NULL)
	{
		return (-1);
	}
	else if (s1 != NULL && s2 == NULL)
	{
		return (1);
	}

	while (*(s1 + i) != '\0')
	{
		if (*(s1 + i) == *(s2 + i))
		{
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
