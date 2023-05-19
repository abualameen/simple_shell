#include "main.h"

/**
 * _strchr - search by compareing a char to a str returns if a match is found
 * @str: str to compared
 * @n:  compared str
 * Return: 0
 */

char *_strchr(char *str, int n)
{
	while (str != NULL)
	{
		if (*str == n)
		{
			return (str);
		}
	}
	return (NULL);
}
