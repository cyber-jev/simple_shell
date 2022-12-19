#include "shell.h"

/**
 * _realloc - Reallocates pointer in order to double the space
 * @ptr: Old array's pointer
 * @size: Pointer to old array's number of elements
 *
 * Return: Pointer to the new array
 */

char **_realloc(char **ptr, size_t *size)
{
	char **new;
	size_t x = 0;

	new = malloc(sizeof(char *) * ((*size) + 10));

	if (new == NULL)
	{

		free(ptr);
		return (NULL);
	}

	for (x = 0; x < (*size); x++)
	{
		new[x] = ptr[x];
	}

	*size += 10;
	free(ptr);

	return (new);
}
