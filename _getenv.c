#include "main.h"

/**
 * _getenv - prints the environment
 * @name: enviroment variable to get
 * Return: Always 0.
 */

char *_getenv(const char *name)
{
	extern char **environ;
	int i, j;
	int strcomm;
	char delim = '=';
	char *part_a = malloc(1025);
	char *part_b = malloc(1025);

	if (part_a == NULL)
	{
		printf("malloc err1");
	}
	if (part_b == NULL)
	{
		printf("malloc erro2");
	}
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			if (environ[i][j] == '=')
			{
				break;
			}
		}
		_slit_str(environ[i], part_a, part_b, delim);
		strcomm = _strcom(part_a, name);
		if (strcomm == 0)
		{
			break;
		}
	}
	free(part_a);
	return (part_b);
}
