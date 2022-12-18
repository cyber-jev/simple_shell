#include "shell.h"

/**
 * _strcat - Concatenates two strings
 * @strc1: String 1
 * @strc2: string 2
 * Return: Pointer
 */

char *_strcat(char *strc1, char *strc2)
{

	char *newstring;
	unsigned int len1, len2, newlen, i, j;

	len1 = 0;
	len2 = 0;

	if (strc1 == NULL)
		len1 = 0;
	else
	{

		for (len1 = 0; strc1[len1]; len1++)
			;
	}
	if (strc2 == NULL)

		len2 = 0;
	else
	{
		for (len2 = 0; strc2[len2]; len2++)
			;
	}

	newlen = len1 + len2 + 2;

	newstring = malloc(newlen * sizeof(char));

	if (newstring == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)

		newstring[i] = strc1[i];
	newstring[i] = '/';
	for (j = 0; j < len2; j++)

		newstring[i + 1 + j] = strc2[j];
	newstring[len1 + len2 + 1] = '\0';
	return (newstring);
}
