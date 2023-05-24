#include "main.h"
/**
 * read_lin - reads line from stdin
 * @tks: tokens
 * Return: void
 */

int read_lin(char *tks[])
{
	ssize_t read_line;
	char *lineptr = NULL;
	size_t n = 0;
	char *token_line;
	int c;

	read_line = _get_line(&lineptr, &n, stdin);
	if (read_line == -1)
	{
		perror("error read_line\n");
		exit(1);
	}
	c = 0;
	token_line = _strtok(lineptr, " \n");
	while (token_line)
	{
		tks[c] = _strdup(token_line);
		c++;
		token_line = _strtok(NULL, " \n");
	}
	tks[c] = NULL;
	free(lineptr);
	lineptr = NULL;
	return (c);
}
