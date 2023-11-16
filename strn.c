#include "shell.h"

/**
 * _strcat - a function that concatenates strings
 * @dest: the destination input
 * @src: the source string value
 * Return: 0
 */

char *_strcat(char *dest, char *src)
{
	int a = 0;

	int len = _strlen(dest);

	while (src[a] != '\0')
	{
		dest[len] = src[a];
		len++;
		a++;
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strcpy -function that copies strings
 * @dest: copied string
 * @src: the source string to copy
 * Return: 0
 */

char *_strcpy(char *dest, char *src)
{
	int len, a;

	len = _strlen(src);

	for (a = 0; a < len; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp - a function that compares two strings
 * @str1: the first string input
 * @str2: the second string input
 * Return: 0 if equal, <0 if str1 is less than str2
 * >0 if str1 is greater than str2
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return (0);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * _strdup - a function that duplicates input strings
 * @s: the string value
 * Return: the pointer to the copied string or NULL if error
 */

char *_strdup(char *s)
{
	char *c;
	unsigned int a = 0, len = 0;

	if (s == NULL)
		return (NULL);

	while (s[len])
		len++;

	c = malloc(sizeof(char) * (len + 1));

	if (c == NULL)
		return (NULL);
	while ((c[a] = s[a]) != '\0')
		a++;
	return (c);
}

/**
 * _strlen - function that return the len of a string
 * @c: char value
 * Return: 0
 */

int _strlen(char *c)
{
	int a = 0;

	while (c[a] != '\0')
	{
		a++;
	}
	return (a);
}
