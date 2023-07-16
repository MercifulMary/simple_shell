#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int add_char(char c, char **word, int *wc);
int add_word(char ***arr, long *pos, char *word, int *wc);

/**
 * _strtok - function to split string to an array
 * @arr: the address of the array to split string into
 * @line: string
 * @delim: delimeter
 *
 * Return: the size of the array
 */
long _strtok(char ***arr, char *line, char *delim)
{
	int i = 0;
	char c = '0';
	long pos = 0;
	int wc = 0;
	char *word = "";

	if (line == NULL)
		return (0);

	if (delim == NULL)
	{
		*arr = malloc(sizeof(char *));
		if (*arr == NULL)
			return (0);

		*arr[0] = line;
		return (1);
	}

	while (!((*(line + i) == '\0')))
	{
		if (*(line + i) == '\n' && *(line + i + 1) == '\0')
		{
			*(line + i) = '\0';
			break;
		}
		c = *(line + i);
		if (c == *delim)
			add_word(arr, &pos, word, &wc);
		else
			add_char(c, &word, &wc);
		i++;
	}

	if (wc > 0)
		add_word(arr, &pos, word, &wc);

	return (pos);
}

/**
 * add_char - adds a character to a word
 * @c: the character to be added
 * @word: the word
 * @wc: the current word count
 *
 * Return: 1
 */
int add_char(char c, char **word, int *wc)
{
	if (*wc == 0)
	{
		*word = malloc(sizeof(char) + 1);
	}
	else
	{
		*word = realloc(*word, ((sizeof(char) * (*wc)) + 2));
	}

	if (*word == NULL)
	{
		return (-1);
	}

	*(*word + *wc) = c;
	*(*word + *wc + 1) = '\0';
	*wc += 1;

	return (1);
}

/**
 * add_word - adds a word to an array
 * @arr: the array
 * @pos: the current position of the array to add on
 * @word: the word to be added
 * @wc: the current word count
 *
 * Return: an integer
 */
int add_word(char ***arr, long *pos, char *word, int *wc)
{
	long int size = 0;

	if (*wc == 0)
	{
		return (0);
	}

	if (*arr == NULL)
	{
		size = 2;
		*arr = calloc(size, sizeof(char *));
		if (*arr == NULL)
			return (-1);
	}
	else
	{
		size = *pos + 2;
		*arr = reallocarray(*arr, size, (sizeof(char *)));
		if (*arr == NULL)
		{
			free_array(arr, 0);
			return (-1);
		}
	}

	if (*pos < 0 || *wc < 0 || word == NULL)
		return (-1);

	*(*arr + *pos) = malloc((sizeof(char) * (*wc)) + 1);
	if (*(*arr + *pos) == NULL)
	{
		free_array(arr, size);
	}

	if (_strcpy(*(*arr + *pos), word) == NULL)
	{
		free_array(arr, size);
		return (-1);
	}

	(*arr)[size - 1] = NULL;

	*wc = 0;
	*pos += 1;
	free(word);

	return (1);
}
