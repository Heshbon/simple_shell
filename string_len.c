#include "shell.h"

/**
 * _strnlen - function that returns the len of a string
 * @c: the character value of the string
 * Return: 0
 */

int _strnlen(char *c)
{
	int a = 0;

	while (c[a] != '\0')
	{
		a++;
	}
	return (a);
}
