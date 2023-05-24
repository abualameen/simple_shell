#include "main.h"
/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @delim: delim to use
 * Return: 0
 */

char *_strtok(char *str, const char *delim)
{
	static  char *toks_ptr;

	/*toks_ptr = NULL;*/
	if (str == NULL)
	{
		str = toks_ptr;
		if (str == NULL)
		{
			return (NULL);
		}
	}
	str += strspn(str, delim);
	if (*str == '\0')
	{
		toks_ptr = NULL;
		return (toks_ptr);
	}
	toks_ptr = str + strcspn(str, delim);
	if (toks_ptr[0] != '\0')
	{
		toks_ptr[0] = '\0';
		toks_ptr++;
	}
	else
	{
		toks_ptr = NULL;
	}
	return (str);
}
