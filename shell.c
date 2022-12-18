#include "shell.h"

/**
 * sig_handler - Handles ^C signal interupt
 * @uuv: Unused variable
 *
 * Return: Void
 */
static void sig_handler(int uuv)
{
		sigflag_t *x = malloc(sizeof(unsigned int));
		(void) uuv;

	if (x->sig_flag == 0)
		_puts("\n$ ");

	else
		_puts("\n");
	free(x);
}

/**
 * main - Shell main function
 * @argc: Argument numbers passed to main
 * @argv: Argument arrays passed to main
 * @environment: Environment variables
 *
 * Return: 0 or exit status, or ?
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};
	unsigned int is_pipe = 0, i;
	size_t len_buffer = 0;
	sigflag_t *x = malloc(sizeof(unsigned int));

	vars.argv = argv;
	vars.env = make_env(environment);
	signal(SIGINT, sig_handler);
	if (!isatty(STDIN_FILENO))
		is_pipe = 1;
	if (is_pipe == 0)
		_puts("$ ");
	x->sig_flag = 0;
	while (getline(&(vars.buffer), &len_buffer, stdin) != -1)
	{
		x->sig_flag = 1;
		vars.count++;
		vars.commands = tokenize(vars.buffer, ";");
		for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
		{
			vars.av = tokenize(vars.commands[i], "\n \t\r");
			if (vars.av && vars.av[0])
				if (check_for_builtins(&vars) == NULL)
					check_for_path(&vars);
			free(vars.av);
		}
		free(vars.buffer);
		free(vars.commands);
		x->sig_flag = 0;
		if (is_pipe == 0)
			_puts("$ ");
		vars.buffer = NULL;
	}
	if (is_pipe == 0)
		_puts("\n");
	free_env(vars.env);
	free(vars.buffer);
	free(x);
	exit(vars.status);
}
