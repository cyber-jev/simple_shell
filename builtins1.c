include "shell.h"

/**
 * new_exit - Exit program
 * @vars: Variables
 *
 * Return: Void
 */
void new_exit(vars_t *vars)
{
	int status;
	if (_strcmpr(vars->av[0], "exit") == 0 && vars->av[1] != NULL)
	{
		status = _atoi(vars->av[1]);
		if (status == -1)
		{
			vars->status = 2;
			print_error(vars, ": Illegal number: ");
			_puts2(vars->av[1]);
			_puts2("\n");
			free(vars->commands);
			vars->commands = NULL;
			return;
		}
		vars->status = status;
	}
	free(vars->buffer);
	free(vars->av);
	free(vars->commands);
	free_env(vars->env);
	exit(vars->status);
}

/**
 * _env - Print the current working environment
 * @vars: Variable structure
 *
 * Return: Void.
 */
void _env(vars_t *vars)
{
	unsigned int x;

	for (x = 0; vars->env[x]; x++)
	{
		_puts(vars->env[x]);
		_puts("\n");
	}
	vars->status = 0;
}
