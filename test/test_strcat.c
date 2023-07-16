#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_strcat - test strcat
 */
void test_strcat(void)
{
	char *s1, *s2;

	size_t len = 0;
	int n = 0;

	s1 = malloc(sizeof(char) * 120);
	s2 = malloc(sizeof(char) * 120);

	printf("\nInput $str1: ");
	n = getline(&s1, &len, stdin);
	if (n == -1)
	{
		printf("Error: Unable to read line");
		exit(EXIT_FAILURE);
	}
	*(s1 + n - 1) = '\0';

	printf("\nInput $str2: ");
	n = getline(&s2, &len, stdin);
	if (n == -1)
	{
		printf("Error: Unable to read line");
		exit(EXIT_FAILURE);
	}

	s1 = _strcat(s1, s2);

	printf("\nvalue: %s\n", s1);
	free(s1);
	free(s2);
}
