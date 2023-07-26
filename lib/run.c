#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "lib.h"

int exec_process(char *, char ***addr, char **cmd);
int manage_env(char **, char ***);
void exec_custom_commands(char ***, char **);
void finalize(char ***, int, int);


/**
 * run - function to executes a command
 * @addr: the address of the command list array
 * @cmd: the command represented as an array
 * @env: the address of the environment variables
 *
 * Return: 1
 */
int run(char ***addr, char **cmd, char ***env)
{
	int res = 1;
	struct stat st;
	int status;
	pid_t cid;
	char *path = _strcpy(NULL, "/bin/");

	path = _strcat(path, cmd[0]);
	if (path == NULL)
	{
		return (-1);
	}

	res = manage_env(cmd, env);
	if (res == 0)
	{
		cid = fork();
		if (cid == -1)
		{
			_puts(2, "Error creating process\n");
			free(path);
			return (-1);
		}
		else if (cid == 0)
		{
			if (stat(path, &st) != 0)
			{
				free(path);
				exec_custom_commands(addr, cmd);
			}
			else
			{
				res = exec_process(path, addr, cmd);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(path);
	return (res);
}

/**
 * exec_process - function to execute a process
 * @path: the bin path
 * @addr: the addres of the command array
 * @cmd: command array
 *
 * Return: an integer
 */
int exec_process(char *path, char ***addr, char **cmd)
{
	if (execve(path, cmd, NULL) == -1)
	{
		free(path);
		finalize(addr, EXIT_FAILURE, 1);
	}
	free(path);
	return (1);
}

/**
 * exec_custom_commands - function to exectue commands outside stat
 * @addr: the address of the comand list
 * @cmd: the command list
 *
 */
void exec_custom_commands(char ***addr, char **cmd)
{
	if (execve(cmd[0], cmd, NULL) == -1)
	{
		_puts(2, "bash: ");
		_puts(2, cmd[0]);
		_puts(2, ": command not found\n");
		finalize(addr, EXIT_FAILURE, 1);
	}
	finalize(addr, EXIT_SUCCESS, 1);

}

/**
 * manage_env - function to manage environment variables
 * @cmd: the command list
 * @env: the address of the environment variables
 *
 * Return: 1 if successful
 */
int manage_env(char **cmd, char ***env)
{
	if (_strcmp(cmd[0], "printenv") == 0 || _strcmp(cmd[0], "env") == 0)
	{
		_print_env(env);
		return (1);
	}
	else if (_strcmp(cmd[0], "setenv") == 0)
	{
		char *var = NULL;

		if (cmd[1] == NULL || cmd[2] == NULL ||
		cmd[1][0] == '\0' || cmd[2][0] == '\0')
		{
			_puts(2, "Error:Usage: setenv [name] [value]\n");
		}

		var = _strcpy(NULL, cmd[1]);
		var = _strcat(var, "=");
		if (var == NULL)
			return (-1);

		var = _strcat(var, cmd[2]);
		if (var == NULL)
			return (-1);

		_set_env(var, env);
		free(var);
		return (1);
	}
	else if (_strcmp(cmd[0], "unsetenv") == 0)
	{
		if (cmd[1] == NULL || cmd[1][0] == '\0')
			_puts(2, "Error:Usage: unsetenv [name]\n");

		_unset_env(cmd[1], env);
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * finalize - function to free the address of an array and end process
 * @addr: the address of the array
 * @code: the exit status code
 * @end_process: indicates if the process should be terminated
 */
void finalize(char ***addr, int code, int end_process)
{
	free_array(addr, 0);
	if (end_process)
	{
		exit(code);
	}
}
