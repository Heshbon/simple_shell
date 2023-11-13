#include "shell.h"

/**
 * _stncmp - function that compares strings
 * @strn1: the first string
 * @strn2: the second string
 * Return: 0 if equal, <0 if strn1 is less than strn2,
 * >0 if strn1 is greater than strn2
 */
int _stncmp(char *strn1, char *strn2)
{
	while (*strn1 == *strn2)
	{
		if (*strn1 == '\0')
		{
			return (0);
		}
		strn1++;
		strn2++;
	}
	return (*strn1 - *strn2);
}
