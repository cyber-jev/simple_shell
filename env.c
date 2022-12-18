#include "shell.h"
/**
 * make_env - Uses a repica of environment passed to main,
 *            to create the shell environment.
 * @env: Main's environment
 *
 * Return: Pointer to the new environment
 */

char **make_env(char **env)
{
	char **newenv = NULL;
	size_t x;

	for (x = 0; env[x] != NULL; x++)
		;
	newenv = malloc(sizeof(char *) * (x + 1));

	if (newenv == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}

	for (x = 0; env[x] != NULL; x++)
		newenv[x] = _strdup(env[x]);

	newenv[x] = NULL;

	return (newenv);
}

/**
 * free_env - Frees the shell environment
 * @env: Environment
 *
 * Return: Void
 */

void free_env(char **env)
{
	unsigned int x = 0;

	for (; env[x] != NULL; x++)
		free(env[x]);

	free(env);
}
