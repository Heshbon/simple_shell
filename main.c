#include "shell.h"
#include <unistd.h>

/**
 * main - the main function
 * @arc: the argument count
 * @arv: the argument vector
 * @envp: the environment argument
 * Return: 0
 */

int main(int arc, char **arv, char **envp)
{
	if (arc == 1)

	rncmd(arv, envp);

	return (0);
}
