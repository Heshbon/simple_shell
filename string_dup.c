#include "shell.h"

/**
 * *_strndup - function that dup a strn
 * @strn: the strn input
 * Return: the pointer to the copied strn or NULL
 */

char *_strndup(const char *strn)
{
	char *n;
	unsigned int a = 0, len = 0;

	if (strn == NULL)
		return (NULL);

	while (strn[len])
		len++;

	n = malloc(sizeof(char) * (len + 1));

	if (n == NULL)
		return (NULL);

	while ((n[a] = strn[a]) != '\0')
		a++;

	return (n);
}
