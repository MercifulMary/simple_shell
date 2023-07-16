#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "test.h"
#include "../lib/lib.h"

void test(int i, char ***env);
void print_intro(void);

/**
 * main - test file
 * @ac: arg
 * @av: arg
 * @env: arg
 *
 * Return: 0
 */
int main(int ac, char *av[], char **env)
{
	int i;

	if (ac == 1)
	{
		print_intro();
		scanf("%d", &i);
		getchar();
	}
	else
	{
		if (ac != 2)
		{
			printf("Invalid number of arguments\n");
			return (EXIT_FAILURE);
		}

		if (!(*av[1] >= 48 && *av[1] < 48 + 10))
		{
			printf("Invalid input\n");
			return (EXIT_FAILURE);
		}

		i = *av[1] - 48;
	}

	test(i, &env);
	return (0);
}

/**
 * test - switch input
 * @i: input value
 * @env: the address of the environment variabls
 */
void test(int i, char ***env)
{
	switch (i)
	{
		case 0:
			test_print_env(env);
			break;
		case 1:
			test_getline();
			break;
		case 2:
			test_strcmp();
			break;
		case 3:
			test_strncmp();
			break;
		case 4:
			test_strlen();
			break;
		case 5:
			test_strcpy();
			break;
		case 6:
			test_strtok();
			break;
		case 7:
			test_strcat();
			break;
		case 8:
			test_run(env);
			break;
		case 9:
			test_append_path();
			break;
		default:
			printf("Unsupported value entered");
			break;
	}
}

/**
 * print_intro- print welcome
 */
void print_intro(void)
{
	printf("Testing Unix Shell Interpreter\n\n");
	printf("Press 0: to test _prin_env\n");
	printf("Press 1: to test _getline\n");
	printf("Press 2: to test _strcmp\n");
	printf("Press 3: to test _strncmp\n");
	printf("Press 4: to test _strlen\n");
	printf("Press 5: to test _strcpy\n");
	printf("Press 6: to test _strtok\n");
	printf("Press 7: to test _strcat\n");
	printf("Press 8: to test run\n");
	printf("Press 9: to test append path\n");
}
