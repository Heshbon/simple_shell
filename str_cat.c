#include "shell.h"

/**
 * *_strcat - function that concatenates a string
 * @dest: the pointer to destination string
 * @src: the pointer to source string
 * Return: pointer to destination string
 */

char *_strcat(char *dest, char *src)
{
	int a = 0;

	int len = _strnlen(dest);

	while (src[a] != '\0')
	{
		dest[len] = src[a];
		len++;
		a++;
	}
	dest[len] = '\0';
	return (dest);
}
