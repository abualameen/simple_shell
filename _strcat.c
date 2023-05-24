#include "main.h"

/**
 * _strcat - the function concatenates strings
 * @dest: the destination
 * @src: the source loca
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int g;
	int count = 0;
	int f;
	int t;
	int countt = 0;

	for (g = 0; dest[g] != '\0'; g++)
	{
		count++;
	}
	for (t = 0; src[t] != '\0'; t++)
	{
		countt++;
	}
	for (f = 0; f < countt; f++)
	{
		dest[count + f] = src[f];
	}
	dest[count + countt] = '\0';
	return (dest);
}
