#include "shell.h"
/**
 *excute_command - excute the specific command
 *@args: parameter to be checked
 *Return: void
 */
void excute_command(char *args[])
{
	int i, status;
	pid_t pid;
	char buffer[1024];

	write(STDOUT_FILENO, "Executing command ", 20);
	for (i = 0; args[i] != NULL; i++)
	{
		write(STDOUT_FILENO, args[i], strlen(args[i]));
		write(STDOUT_FILENO, " ", 1);
	}
	write(STDOUT_FILENO, "\n", 1);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		sprintf(buffer, "Command executed with status %d\n", status);
		write(STDOUT_FILENO, buffer, strlen(buffer));
	}
}
