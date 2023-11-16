#include "shell.h"

/**
 * _getenv - environment var
 * @var: the envi var
 * Return: 0
 */

char *_getenv(char *var)
{
	int a = 0;

	for (a = 0; environ[a]; a++)
	{
		if (_str_cmp(environ[a], var, _strlen(var)) == 0)
			return (&environ[a][_strlen(var)]);
	}
	return (NULL);
}
