#include <stdio.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_getline - test getline
 */
void test_getline(void)
{
	char *s;

	printf("\nInput $: ");
	fflush(stdout);
	s = _getline();

	printf("\nvalue: %s\n", s);
}
