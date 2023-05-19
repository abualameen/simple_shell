#include "main.h"
/**
 * read_lin - reads line from stdin
 * @tks: tokens
 * Return: void
 */

void read_lin(char *tks[])
{
	ssize_t read_line;
	char *lineptr = NULL;
	size_t n = 0;
	int j;
	char *token_line;

	read_line = _get_line(&lineptr, &n, stdin);
	if (read_line == -1)
	{
		perror("error read_line\n");
		exit(1);
	}

	j = 0;
	token_line = strtok(lineptr, " \n");
	while(token_line)
	{
		tks[j] = token_line;
		j++;
		token_line = strtok(NULL, " \n");
	}
	tks[j] = NULL;
}
