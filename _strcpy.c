#include "main.h"

/**
 * _strcpy - function that copys str
 * @dest: function param
 * @src: function argument
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int f;
	int g;
	int count = 0;
	for (f = 0; src[f] != '\0'; f++)
	{
		count++;
	}
	for (g = 0; g < count; g++)
	{
		dest[g] = src[g];
	}
	dest[count] = '\0';
	return (dest);
}
