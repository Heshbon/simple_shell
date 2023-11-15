#include "shell.h"

#include <sys/stat.h>

/**
 * handle_path - function that handles the path
 * @command: the command passed
 * @args: arguments
 * Return: the new path in the command read
 */
char *handle_path(char *command)
{
	struct stat buffer;
	int l, dl;
	char *path, *path_copy, *token, *file_path;

	path = getenv("PATH");
	
	if (path)
	{
		path_copy = strdup(path);
		l = strlen(command);
		token = strtok(path_copy, ":");
		while (token != NULL)
		{
			dl = strlen(token);
			file_path = malloc(l + dl + 2);
			strcpy(file_path, token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if  (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL); 
	}
	return (NULL);
}
