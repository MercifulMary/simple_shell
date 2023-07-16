#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
 * _strcat - appends a string to another
 * @s1: string 1
 * @s2: string 2
 *
 * Return: pointer to the new string
 */
char *_strcat(char *s1, char *s2)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int sum1 = _strlen(s1);
	unsigned int sum2 = _strlen(s2);
	char *s = NULL;

	if (s1 == NULL && s2 == NULL)
		return (NULL);

	s = malloc((sizeof(char) * (sum1 + sum2)) + 1);
	if (s == NULL)
		return (NULL);

	while (s1 != NULL && (*(s1 + i) != '\0'))
	{
		*(s + i) = *(s1 + i);
		i++;
	}

	while (s2 != NULL && (*(s2 + j) != '\0'))
	{
		*(s + i) = *(s2 + j);
		i++;
		j++;
	}

	*(s + i) = '\0';

	s1 = NULL;
	s1 = _strcpy(s1, s);
	free(s);
	/*free(s2);*/

	return (s1);
}
