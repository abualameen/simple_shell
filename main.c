#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char *lineptr, *token;
	char cpy[1024];
	size_t n = 1024;
	ssize_t read_line;

	while (1)
	{
		/*_putchar('$');
		_putchar(' ');*/
		lineptr = malloc(sizeof(char) * n);
		read_line = getline(&lineptr, &n, stdin);
		if (read_line == -1)
		{
			free(lineptr);
			exit(0);
		}
		_strcpy(cpy, lineptr);
		token = strtok(lineptr, " \n");
		while (token)
		{
			token = strtok(NULL, " \n");
		}
		free(lineptr);
		execution(cpy);
	}
	return (0);
}
