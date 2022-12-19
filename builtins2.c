include "shell.h"

/**
 * new_setenv - Creates or edits environment variable
 * @vars: Pointer to structure of variables
 *
 * Return: void
 */
void new_setenv(vars_t *vars)
{
	char **keys;
	char *var;
	
	if (vars->av[1] == NULL || vars->av[2] == NULL)
	{
		print_error(vars, ": Incorrect number of arguments\n");
		vars->status = 2;
		return;
	}
	keys = find_key(vars->env, vars->av[1]);
	
	if (keys == NULL)
		add_key(vars);
	else
	{
		var = add_value(vars->av[1], vars->av[2]);
		if (var == NULL)
		{
			print_error(vars, NULL);
			free(vars->buffer);
			free(vars->commands);
			free(vars->av);
			free_env(vars->env);
			exit(127);
		}
		free(*keys);
		*keys = var;
	}
	vars->status = 0;
}
