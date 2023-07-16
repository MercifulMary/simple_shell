#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_strncmp - test strncmp
 */
void test_strncmp(void)
{
	char *s1, *s2;
	int d, n;

	s1 = malloc(sizeof(char) * 120);
	s2 = malloc(sizeof(char) * 120);

	printf("\nInput $str1: ");
	scanf("%s", s1);
	getchar();

	printf("\nInput $str2: ");
	scanf("%s", s2);
	getchar();

	printf("\nInput $length: ");
	scanf("%d", &n);
	getchar();

	d = _strncmp(s1, s2, n);

	printf("\nvalue: %d\n", d);
	free(s1);
	free(s2);
}
