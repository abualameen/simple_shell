#include "main.h"
/**
 * fgett - gets chunk of char
 * @buffer: container for char
 * @buffersize: size of buff
 * @stream: stream from where char is read
 * Return: 0
 */



char *fgett(char *buffer, int buffersize, FILE *stream)
{
	int no_read;

	if (buffer == NULL || buffersize <= 0 || stream == NULL)
	{
		return (NULL);
	}

	no_read = read(STDIN_FILENO, buffer, buffersize - 1);
	if (no_read == -1)
	{
		perror("error from read");
		return (NULL);
	}
	if (no_read == 0)
	{
		return (NULL);
	}
	buffer[no_read] = '\0';
	return (buffer);
}
