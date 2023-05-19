#include "miin.h"
#define LIN_MAX 3000
int line_no(void);
/**
 * _get_line - getline input from user
 * @lineptr: contains line read
 * @n: size of buff pointed to by lineptr
 * @stream: stream where input is taken
 * Return: void
 */


ssize_t _get_line(char **lineptr, size_t *n, FILE *stream)
{
	char buf[LIN_MAX];
	ssize_t nbytes;
	char *new_lineptr;

	*n = LIN_MAX;
	if (lineptr == NULL || n == NULL)
	{
		perror("_getline argument error");
		return (-1);
	}
	if (stream == NULL)
	{
		perror("_getline stream argument error");
		return (-1);
	}
	if (*lineptr == NULL)
	{
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			perror("malloc failed for lineptr");
			return (-1);
		}
	}
	(*lineptr)[0] = '\0';
	while ((nbytes = read(STDIN_FILENO, buf, *n)) > 0)
	{
		if (*n - _strlen(*lineptr) < sizeof(buf))
		{
			*n *= 2;
			new_lineptr = malloc(*n);
			if (new_lineptr == NULL)
			{
				perror("malloc error of new_lineptr");
				return (-1);
			}
			_strcpy(new_lineptr, *lineptr);
			free(*lineptr);
			*lineptr = new_lineptr;
		}
		_strcat(*lineptr, buf);
		if ((*lineptr)[_strlen(*lineptr) - 1] == '\n')
		{
			return (_strlen(*lineptr));
		}
	}
	free(*lineptr);
	*lineptr = NULL;
	return (-1);
}

/**
 * line_no - checks
 * Return: 0
 */

int line_no(void)
{
	return (0);
}
