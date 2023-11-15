#include "shell.h"
/**
 * main - the main function
 *
 * Return: void
 */
int main(void)
{
	char command_line[MAX_COMMAND_LENGTH];
	int exit_status;

	while (1)
	{
		display_prompt();
		if (fgets(command_line, sizeof(command_line), stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("fgets");
				exit(EXIT_FAILURE);
			}
		}
		command_line[strcspn(command_line, "\n")] = '\0';
		exit_status = excute_command(command_line);
		if (exit_status == -1)
		{
			fprintf(stderr, "Error excuting command: %s\n", command_line);
		}
	}
	return (0);
}
