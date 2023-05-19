#include "main.h"

/**
 * _slit_str - slipts a str into two parts
 * @s: string to slipt
 * @part1: buffer to store the first part
 * @part2: buffer to stor the second part
 * @delim: delimeter used for sliting
 * Return: 0
 */


void _slit_str(char *s, char *part1, char *part2, char delim)
{
	int a, b, c, d;
	int count = 0;
	char *s_cp;
	char *dst;
	
	a = b = c = 0;
	count = _strlen(s);
	dst = malloc(sizeof(char *) * count);
	s_cp = _strcpy(dst, s);

	while (s[a] != '\0')
	{
		if (s[a] != delim)
		{
			part1[a] = s[a];
			c++;
		}
		else if (s[a] == delim)
		{
			part1[a] = '\0';
			break;
		}
		a++;
	}
	d = a + 1;
	for (b = 0; s_cp[b] != '\0'; b++)
	{
		part2[b] = s_cp[d];
		d++;
	}
	free(dst);
}
