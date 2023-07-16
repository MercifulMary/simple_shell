#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_strlen - test strlen
 */
void test_strlen(void)
{
	char *s;
	int d;

	s = malloc(sizeof(char) * 120);

	printf("\nInput $ : ");
	scanf("%s", s);
	getchar();

	d = _strlen(s);

	printf("\nvalue: %d\n", d);
	free(s);
}
