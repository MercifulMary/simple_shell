#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_strcmp - test strcmp
 */
void test_strcmp(void)
{
	char *s1, *s2;
	int d;

	s1 = malloc(sizeof(char) * 120);
	s2 = malloc(sizeof(char) * 120);

	printf("\nInput $str1: ");
	scanf("%s", s1);
	getchar();

	printf("\nInput $str2: ");
	scanf("%s", s2);
	getchar();

	d = _strcmp(s1, s2);

	printf("\nvalue: %d\n", d);
	free(s1);
	free(s2);
}
