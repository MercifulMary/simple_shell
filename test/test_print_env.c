#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "../lib/lib.h"

/**
 * test_print_env - test printenv
 * @env: the address of the environment variables
 */
void test_print_env(char ***env)
{
	_print_env(env);
}
