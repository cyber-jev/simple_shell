#include "shell.h"
/**
 * print_error - Prints an error messages
 * @vars: Pointer to struct of variables
 * @msg: Error message
 *
 * Return: void
 */
void print_error(vars_t *vars, char *msg)
{
	char *count;

	_puts2(vars->argv[0]);
	_puts2(": ");
	count = _uitoa(vars->count);
	_puts2(count);
	free(count);
	_puts2(": ");
	_puts2(vars->av[0]);

	if (msg)
	{
		_puts2(msg);
	}

	else
		perror("");
}

/**
 * _puts2 - Prints a string to standard error
 * @str: String
 *
 * Return: Void
 */
void _puts2(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDERR_FILENO, str, num);

	if (len != num)
	{
		perror("Fatal Error");
		exit(1);
	}
}

/**
 * _uitoa - Converts an unsigned integer to string
 * @count: Unsigned integer
 *
 * Return: Pointer to the converted string
 */
char *_uitoa(unsigned int count)
{
	char *numstr;
	unsigned int tmp, digits;

	tmp = count;

	for (digits = 0; tmp != 0; digits++)
		tmp /= 10;
	numstr = malloc(sizeof(char) * (digits + 1));

	if (numstr == NULL)
	{
		perror("Fatal Error1");
		exit(127);
	}

	numstr[digits] = '\0';

	for (--digits; count; --digits)
	{
		numstr[digits] = (count % 10) + '0';
		count /= 10;
	}

	return (numstr);
}
