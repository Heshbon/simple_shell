#include "shell.h"
/**
 * main - the main function
 * @arc: the argument count
 * @arv: the argument vector
 * Return: 0
 */
int main(int arc, char **argv)
{
	char *promt = "Myshell$";
	char *ptr = NULL, *ptr_copy = NULL;
	size_t num = 0;
	ssize_t nchars_read;
	const char *d = "\n";
	int tokens = 0;
	char *token;
	int i;

	(void)arc;
	while (1)
	{
		printf("%s", promt);
		nchars_read = getline(&ptr, &num, stdin);
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}
		ptr_copy = malloc(sizeof(char *) * nchars_read);
		if (ptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		strcpy(ptr_copy, ptr);
		token = strtok(ptr, d);
		while (token != NULL)
		{
			tokens++;
			token = strtok(NULL, d);
		}
		tokens++;
		argv = malloc(sizeof(char *) * tokens);
		token = strtok(ptr_copy, d);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, d);
		}
		argv[i] = NULL;
		excute_command(argv);
	}
	free(ptr_copy);
	free(ptr);
	return (0);
}
