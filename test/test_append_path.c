#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_append_path - test append path
 */
void test_append_path(void)
{
	char **arr = NULL;
	char *s = "";
	int count = 0;
	int i = 0;
	char *delim = " ";
	size_t len = 0;
	int n = 0;

	printf("\nInput $: ");
	n = getline(&s, &len, stdin);
	if (n == -1)
	{
		printf("Error: Unable to read line");
		exit(EXIT_FAILURE);
	}
	fflush(stdout);

	count = _strtok(&arr, s, delim);

	if (arr == NULL)
	{
		printf("\nError: Nothing to return");
	}
	else
	{
		int err = append_path(&arr, count);

		if (err == -1)
			printf("Error appending path");

		while (i < count)
		{
			printf("\n%i: %s", i, arr[i]);
			i++;
		}
	}

	printf("\nvalue: %s\n", s);
}
