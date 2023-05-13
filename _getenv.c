#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _slit_str(char *s, char *part1, char *part2, char delim);
int strcom(const char *str1, const char *str2);

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
char *_getenv(const char *name)
{
	extern char **environ;
	int i, j;
	int strcomm;
	char delim = '=';
	char *part_a = malloc(1025);
        char *part_b = malloc(1025);
	if (part_a == NULL)
	{
		printf("malloc err1");
	}
	if (part_b == NULL)
	{
		printf("malloc erro2");
	}

       /* _slit_str(s, part_a, part_b, delim);
        printf("%s\n", part_a);
        printf("%s\n", part_b);
	char *envi = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/git/bin";*/
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
		{
			if (environ[i][j] == '=')
			{
				break;
			}
		}
		/*printf("= fountd");*/
		_slit_str(environ[i], part_a, part_b, delim);
		strcomm = strcom(part_a, name);

		if (strcomm == 0)
		{
			/*printf("part_a == PATH");*/
			/*printf("%d\n", strcomm);*/
			break;
		}
		else
		{
			printf("PATH not same with name");
		}
		/*printf("%s\n", part_a);
		printf("%s\n", part_b);*/
		
	}
	free(part_a);
	return (part_b);
}
/*int main(void)
{
	char s[] = "PATH=/upppppppppppppppppppppppppppplllppppppsr";        
	char delim = '=';
        char part_a[1025];
        char part_b[1025];
        _slit_str(s, part_a, part_b, delim);
        printf("%s\n", part_a);
        printf("%s\n", part_b);
	char *pa = _getenv("PATH");
	if (pa != NULL)
	{
		printf("%s\n", pa);
	}
	else
	{
		printf("PATH is not set.\n");
	}
	free(pa);
	return (0);
}*/


int strcom(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);	
}

void _slit_str(char *s, char *part1, char *part2, char delim)
{
        int a, b, c, d;
        int count = 0;
        a = b = c = 0;
       /* char part_a[1025];
        char part_b[1025];*/
        char *s_cp;
        char *dst;

        count = _strlen(s);
        dst = malloc(sizeof(char *) * count);
        s_cp = _strcpy(dst, s);
       /* printf("%s\n", s_cp);*/

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
       /* printf("%d\n", a);
        printf("%d\n", c);*/
        d = a + 1;
        for (b = 0; s_cp[b] != '\0'; b++)
        {
                part2[b] = s_cp[d];
                d++;
        }
        free(dst);
}

char *_strcpy(char *dest, char *src)
{
        int f;
        int g;
        int count = 0;
        char *dst;


        count = _strlen(src);
        /*dst = malloc(sizeof(char *) * count);*/
        for (g = 0; g < count; g++)
        {
                dest[g] = src[g];
        }
        dest[count] = '\0';
        return (dest);
}

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


/*int main(void)
{
        char s[] = "PATH=/upppppppppppppppppppppppppppplllppppppsr";        char delim = '=';
        char part_a[1025];
        char part_b[1025];
        _slit_str(s, part_a, part_b, delim);
        printf("%s\n", part_a);
        printf("%s\n", part_b);
        return (0);
}*/





















