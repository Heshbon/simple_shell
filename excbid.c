#include "shell.h"
/**
 *excute_command - function that handle command
 *@status: parameter to be checked
 *@args: array to hold arguments
 *Return: 0 (success)
 */
int excute_command(int status, char *args[])
{
	char input[100], *tokens[10], *token,*command;
	int pid, i;
	ssize_t r;
	int j = 0;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		r = read(STDOUT_FILENO, input, sizeof(input));
		if (r <= 0)
		{
			break;
		}
		input[r] = '\0';
		token = strtok(input, " ");
		while (token != NULL)
		{
			tokens[j++] = token;
			token = strtok(NULL, " ");
		}
		if (args == NULL)
		{
			perror("ERROR");
			exit(1);
		}
		for (i = 1; i < j; i++)
		{
			args[i - 1] = strdup(tokens[i]);
		}
		args[j - 1] = NULL;
		command = tokens[0];
		if (strcmp(command, "exit") == 0)
		{
			free(args);
			exit(EXIT_FAILURE);
		}
		else 
		{
			pid = fork();
		       if (pid == 0)
			{
				execve(command, args, NULL);
				perror("execve");
			}
			else if (pid > 0)
			{
				waitpid(pid, &status, 0);
			}
			else
			{
				perror("ERROR");
			}
			for (i = 0; args[i] != NULL; i++)
			{
				free(args[i]);
			}
			free(args);
		}
	}
	return (0);

}
