#include "main.h"

/**
 * _strlen - finding the len of a str
 * @s: parameter of function
 * Return: count
 */
int _strlen(char *s)
{
	int h;
	int count = 0;
	for (h = 0; s[h] != '\0'; h++)
	{
		count++;
	}
	return (count);
}
