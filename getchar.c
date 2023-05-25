#include "main.h"

/**
 * _getchar - equivalent to getc(stdin)
 *
 * Return: character read as an unsigned char
 * cast to an int or EOF on end of file or error
 */
int _getchar(void)
{
	int i;
	static char staticbuf[1024];
	static char *bufferpointer = staticbuf;
	static int statint;

	if (statint == 0)
	{
		statint = read(0, staticbuf, 1024);
		bufferpointer = staticbuf;
	}
	if (--statint >= 0)
	{
		i = (unsigned char) *bufferpointer++;
	}
	else
	{
		i = EOF;
	}
	if (i == EOF)
		return (EOF);
	return (i);
}
