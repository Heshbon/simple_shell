#include "shell.h"

/**
 * rncmd - a function that display a prompt
 * and wait for the user to type a command
 * @arv: the argument vector
 * @envp: the argument environment
 */

void rncmd(char **arv, char **envp)
{
	char *c = NULL;
	int a, stat;
	size_t b = 0;
	ssize_t p;
	char *argv[] = {NULL, NULL};
	pid_t mychild;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");

		p = getline(&c, &b,  stdin);
		if (p == -1)
		{
			free(c);
			exit(EXIT_FAILURE);
		}
		a = 0;
		while (c[a])
		{
			if (c[a] == '\n')
				c[a] = 0;
			a++;
		}
		argv[0] = c;
		mychild = fork();
		if (mychild == -1)
		{
			free(c);
			exit(EXIT_FAILURE);
		}
		if (mychild == 0)
		{
			if (execve(argv[0], arv, envp) == -1)
				printf("%s: No such file or directory\n", arv[0]);
		}
		else
			wait(&stat);
	}
}
