#include "main.h"

/**
 * _strdup - dup string
 * @str: string;
 * Return: 0
 */

char *_strdup(char *str)
{
	size_t len;
	char *str_new;

	len = _strlen(str) + 1;
	str_new = malloc(len);

	if (str_new != NULL)
	{
		_strcpy(str_new, str);
	}
	return (str_new);
}
