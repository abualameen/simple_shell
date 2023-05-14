#include "main.h"

/**
 * main - entry point
 *
 * Return: 0
 */
int main(void)
{
	char *lineptr, *cpy, *token, *tokeeen;
	size_t n = 32;
	ssize_t read_line;
	int arguments;

	while (1)
	{
		arguments = 0;
		printf("$ ");
		lineptr = malloc(sizeof(char) * n);
		read_line = getline(&lineptr, &n, stdin);
		if (read_line == -1)
		{
			perror("exit\n\n\n[Disconnected...]");
			exit(1);
		}
		cpy = malloc(sizeof(char) * read_line);
		if (!cpy)
			return (-1);
		_strcpy(cpy, lineptr);
		token = strtok(lineptr, " \n");
		while (token)
		{
			arguments++;
			token = strtok(NULL, " \n");
		}
		if (arguments >= 1)
			arguments++;
		execution(cpy, arguments);
		free(lineptr);
		free(cpy);
	}
	return (0);
}
