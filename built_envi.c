#include "shell.h"

/**
 * print_env - prints the enviro
 * Return: 0
 */

int print_env(void)
{
	char *c = environ[0];
	int a = 0;

	while (c)
	{
		write(1, c, _strlen(c));
		write(1, "\n", 1);
		c = environ[++a];
	}
	return (0);
}

/**
 * _str_cmp - function that compares str1 and str2 bytes
 * @st1: the first string value
 * @st2: the second string value
 * @n: the number of bytes
 * Return: 0 if equal, >0 if str1 is greater than str2
 * <0 if str1 is less thab str2
 */

int _str_cmp(char *st1, char *st2, int n)
{
	char j1, j2;

	while (n--)
	{
		j1 = *st1++;
		j2 = *st2++;

		if (j1 == '\0' || j1 != j2)
			return (j1 > j2 ? 1 : (j1 < j2 ? -1 : 0));
	}
	return (0);
}
