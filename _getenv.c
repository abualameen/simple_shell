#include "main.h"

/**
 * _getenv - prints the environment
 * @name: enviroment variable to get
 * Return: Always 0.
 */

char *_getenv(const char *name)
{
	int i, j;
	int strcomm;
	char delim = '=';
	char *part_a;
	char *part_b;
	size_t part_a_len = 0;
	size_t part_b_len = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			if (environ[i][j] == '=')
			{
				part_a_len = j;
				part_b_len = _strlen(environ[i]);
				break;
			}
		}
		part_a = malloc(part_a_len + 1);
		part_b = malloc(part_b_len + 1);
		if (part_a == NULL || part_b == NULL)
		{
			perror("malloc error for _getenv");
			exit(1);
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
