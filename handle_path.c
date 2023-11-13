#include "shell.h"

#include <sys/stat.h>

/**
 * handle_path - function that handles the path
 * @command: the command passed
 * Return: the new path in the command read
 */

char *handle_path(char *command)
{
	char *p = _strndup(getenv("PATH"));
	int a = 0, n = 0;
	char *m = strtok(p, ":");
	char *p_array[100];
	char *strn2 = command;
	char *b = NULL;
	struct stat buf;

	b = malloc(sizeof(char) * 100);
	if (getenv("PATH")[0] == ':')
		if (stat(command, &buf) == 0)
			return (_strndup(command));
	while (m != NULL)
	{
		p_array[a++] = m;
		m = strtok(NULL, ":");
	}
	p_array[a] = NULL;
	for (n = 0; p_array[n]; n++)
	{
		_strncpy(b, p_array[n]);
		_strcat(b, "/");
		_strcat(b, strn2);
		_strcat(b, "\0");

		if (stat(b, &buf) == 0)
		{
			free(p);
			return (b);
		}
		else
			b[0] = 0;
	}
	free(p);
	free(b);

	if (stat(command, &buf) == 0)
		return (_strndup(command));
	return (NULL);
}
