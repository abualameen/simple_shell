#include <stdio.h>
#include <stdlib.h>
int _strlen(char *s);
char *_strcpy(char *dest, char *src);



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
	printf("%s\n", s_cp);

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
	printf("%d\n", a);
	printf("%d\n", c);
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
	char s[] = "PATH=/upppppppppppppppppppppppppppplllppppppsr";
	char delim = '=';
	char part_a[1025];
	char part_b[1025];
	_slit_str(s, part_a, part_b, delim);
	printf("%s\n", part_a);
	printf("%s\n", part_b);
	return (0);
}*/
