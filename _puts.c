#include "shell.h"

/**
 * _puts - Writes a string to standard output
 * @str: String
 *
 * Return: Number of characters printed or -1 on failure
 */

ssize_t _puts(char *str)
{
	ssize_t num, len;
	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);

	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}

	return (len);
}
