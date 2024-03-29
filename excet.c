#include "shell.h"

/**
 * display_prompt - function that display promts
 *
 * Return: void
 */

void display_prompt(void)
{
	const char prompt[] = "$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
 * display_error - function that display errors
 * @message: parameter to checked
 * Return: void
 */

void display_error(char *message)
{
	write(STDERR_FILENO, message, strnlen(message, MAX_COMMAND_LENGTH));
}

/**
 * resolve_command_line - function that handle command line
 * @command_line: parameter to be checked
 * @args: parameter to be checked
 * Return: void
 */

void resolve_command_line(char *command_line, char **args)
{
	char *token;
	int j;

	token = strtok(command_line, " ");
	while (token != NULL && j < MAX_ARG_COUNT - 1)
	{
		args[j++] = token;
		token = strtok(NULL, " ");
	}
	args[j] = NULL;
}

/**
 * excute_command - main function
 * @command: parameter to check
 * Return: -1
 */

int excute_command(char *command)
{
	char *args[2];
	char *envp[] = {NULL};
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;
		execve(args[0], args, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	else
	{
	return (-1);
	}
}
