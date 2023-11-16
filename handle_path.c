#include "shell.h"

/**
 * handle_path - function that takes handle PATH
 * @cmd: cmd passed
 * Return: the new_path
 */

char *handle_path(char *cmd)
{
	char *p = _strdup(_getenv("PATH"));
	int a = 0, b = 0;
	char *n = strtok(p, ":");
	char *m[256];
	char *str2 = cmd;
	char *j = NULL;
	struct stat buf;

	j = malloc(sizeof(char) * 256);
	if (_getenv("PATH")[0] == ':')
		if (stat(cmd, &buf) == 0)
			return (_strdup(cmd));
	while (n != NULL)
	{
		m[a++] = n;
		n = strtok(NULL, ":");
	}
	m[a] = NULL;
	for (b = 0; m[b]; b++)
	{
		_strcpy(j, m[b]);
		_strcat(j, "/");
		_strcat(j, str2);
		_strcat(j, "\0");

		if (stat(j, &buf) == 0)
		{
			free(p);
			return (j);
		}
		else
			j[0] = 0;
	}
	free(p);
	free(j);

	if (stat(cmd, &buf) == 0)
		return (_strdup(cmd));
	return (NULL);
}

