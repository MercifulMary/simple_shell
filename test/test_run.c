#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_run - test run command
 * @env: the address of the environment variables
 */
void test_run(char ***env)
{
	char **arr = NULL;
	char *s = "";
	int count = 0;
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
		run(arr, env);
	}

	printf("\nvalue: %s (%d)\n", s, count);
}
