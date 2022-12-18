#include "shell.h"
/**
 * add_key - Create a new environment
 * @vars: Pointer to structure of variables
 *
 * Return: Void
 */
void add_key(vars_t *vars)
{
	unsigned int x;
	char **newenv;

	for (x = 0; vars->env[x] != NULL; x++)
		;
	newenv = malloc(sizeof(char *) * (x + 2));

	if (newenv == NULL)
	{
		print_error(vars, NULL);
		vars->status = 127;
		new_exit(vars);
	}

	for (x = 0; vars->env[x] != NULL; x++)
		newenv[x] = vars->env[x];
	newenv[x] = add_value(vars->av[1], vars->av[2]);

	if (newenv[x] == NULL)
	{
		print_error(vars, NULL);
		free(vars->buffer);
		free(vars->commands);
		free(vars->av);
		free_env(vars->env);
		free(newenv);
		exit(127);
	}
	newenv[x + 1] = NULL;
	free(vars->env);
	vars->env = newenv;
}

/**
 * find_key - Finds an environment
 * @env: Environment
 * @key: Key to find environment
 *
 * Return: Pointer to address of the environment
 */
char **find_key(char **env, char *key)
{
	unsigned int x, y, len;

	len = _strlen(key);

	for (x = 0; env[x] != NULL; x++)
	{
		for (y = 0; y < len; y++)
			if (key[y] != env[x][y])
				break;

		if (y == len && env[x][y] == '=')
			return (&env[x]);
	}

	return (NULL);
}

/**
 * add_value - Create a new environment string variable
 * @key: Environment name
 * @value: Environment value
 *
 * Return: Pointer to the new string;
 */
char *add_value(char *key, char *value)
{
	unsigned int len1, len2, x, y;
	char *new;

	len1 = _strlen(key);
	len2 = _strlen(value);
	new = malloc(sizeof(char) * (len1 + len2 + 2));

	if (new == NULL)
		return (NULL);

	for (x = 0; key[x] != '\0'; x++)
		new[x] = key[x];

	new[x] = '=';

	for (y = 0; value[y] != '\0'; y++)
		new[x + 1 + y] = value[y];
	new[x + 1 + y] = '\0';

	return (new);
}
/**
 * _atoi - String to integer converter
 * @str: String
 *
 * Return: The integer value, or -1 if an error occurs
 */
int _atoi(char *str)
{
	unsigned int i, digits;
	int num = 0, num_test;

	num_test = INT_MAX;

	for (digits = 0; num_test != 0; digits++)
		num_test /= 10;

	for (i = 0; str[i] != '\0' && i < digits; i++)
	{
		num *= 10;

		if (str[i] < '0' || str[i] > '9')
			return (-1);

		if ((i == digits - 1) && (str[i] - '0' > INT_MAX % 10))
			return (-1);
		num += str[i] - '0';

		if ((i == digits - 2) && (str[i + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}

	if (i > digits)
		return (-1);

	return (num);
}
