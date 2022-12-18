#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: string
 *
 * Return: length of the string
 */

unsigned int _strlen(char *str)
{

	unsigned int len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}
