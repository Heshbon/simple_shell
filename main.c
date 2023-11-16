#include "shell.h"

/**
 * main - the main function
 *
 * Return: void
 */

int main(void)
{
	char error_message[MAX_COMMAND_LENGTH];
	char *command_line = NULL;
	ssize_t read_b;
	size_t line_size = 0;

	while (1)
	{
		display_prompt();
		read_b = getline(&command_line, &line_size, stdin);
		if (read_b == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		else if (read_b == 0)
		{
			printf("\n");
			break;
		}
		command_line[strcspn(command_line, "\n")] = '\0';
		{
			snprintf(error_message, sizeof(error_message),
			"Error executing command: %s\n", command_line);
			display_error(error_message);
		}
	}
	free(command_line);
	command_line = NULL;
	return (0);
}
