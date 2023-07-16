#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/**
 * free_array - function to release array memory
 * @arr: array
 * @size: the array size
 */
void free_array(char ***arr, int size)
{
	int i = 0;

	if (*arr != NULL)
	{
		if (size != 0)
		{
			if (*arr != NULL)
			{
				for (i = 0; i < size; i++)
				{
					if ((*arr)[i] != NULL)
					{
						free((*arr)[i]);
					}
				}
			}
		}
		else
		{
			while ((*arr)[i] != NULL)
			{
				free((*arr)[i]);
				i++;
			}
		}
		free(*arr);
	}
}
