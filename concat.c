#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: first string
 * @src: second string
 * @newstr: new place to store the string
 * Return: char
 */
char *_strcat(char *dest, char *src, char *newstr)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		newstr[i] = dest[i];
		i++;
	}
	newstr[i] = '/';
	i++;
	while (src[j] != '\0')
	{
		newstr[i] = src[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}
