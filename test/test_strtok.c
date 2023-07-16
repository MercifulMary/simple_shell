#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_strtok - test strtok
 */
void test_strtok(void)
{
	char **arr = NULL;
	char *s = "hi this is Chibuzor. Sup";
	int i = 0;
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

	count = _strtok(&arr, s, delim);

	if (arr == NULL)
	{
		printf("\nError: Nothing to return");
	}
	else
	{
		while (i < count)
		{
			printf("\n%d: %s", i, arr[i]);
			i++;
		}
	}

	printf("\nvalue: %s\n", s);
}
