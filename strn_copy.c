#include "shell.h"

/**
 * _strncpy - function that copies a strn
 * @dest: new destination for the copied string
 * @src: the string to copy
 * Return: 0
 */

char *_strncpy(char *dest, char *src)
{
	int len, a;

	len = _strnlen(src);

	for (a = 0; a < len; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
