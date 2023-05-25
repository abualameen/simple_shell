#include "main.h"

/**
 * _getline - reads an entire line from stream
 * If *lineptr is set to NULL before the call,
 * then getline() will allocate a buffer for storing the line.
 * @lineptr: malloc allocated buffer
 * @n: size auto created
 * @stream: reads from stdin only
 * Return: number of characters read or -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer, *copy;
	int i;
	ssize_t retvalue;

	if (!n || !stream)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		buffer = malloc(1024);
		if (buffer == NULL)
			return (-1);
	}
	else
	{
		buffer = *lineptr;
	}
	i = _getchar();
	if (i == EOF)
		return (-1);
	copy = buffer;
	while (i != EOF)
	{
		*copy++ = i;
		if (i == '\n')
		{
			*copy++ = '\0';
			break;
		}
		i = _getchar();
	}
	retvalue = (signed int) (copy - buffer);
	return (retvalue - 1);
}
