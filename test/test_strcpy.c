#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_strcpy - test strcpy
 */
void test_strcpy(void)
{
	char *src;
	char *dest;
	char *s = NULL;

	src = malloc(sizeof(char) * 120);

	printf("\nInput $ ");
	scanf("%s", src);
	getchar();

	dest = _strcpy(s, src);

	printf("\nvalue: %s\n", dest);
	free(s);
	free(src);
	free(dest);
}
