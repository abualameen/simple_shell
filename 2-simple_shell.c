#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
void _slit_str(char *s, char *part1, char *part2, char delim);
int strcom(const char *str1, const char *str2);
/**
 * main - entry point
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
        char *lineptr = NULL;
        size_t n = 0;
        ssize_t read_line;
        char *token, *token_path;
        const char *delim, *delim_path;
        int j = 0;
        int t, count, count_path;
        extern char **environ;
        char *toks, *toks_path;
        char *path;
        char **argv_path;
        pid_t pid;
        pid_t pid1;

        delim = " \n";
        delim_path = ":";
        while (1)
        {
                printf("$ ");
                read_line = getline(&lineptr, &n, stdin);
                if (read_line == -1)
                {
                        perror("readline failed");
                        exit(1);
                }
                count = _strlen(lineptr);
                toks = malloc(sizeof(char *) * count);
                if (toks == NULL)
                {
                        perror("mem aloca error with toks");
                        exit(1);
                }
                token = strtok(lineptr, delim);
                while (token)
                {
                        argv[j] = _strcpy(toks, token);
                        token = strtok(NULL, delim);
                        j++;
                }
                argv[j] = NULL;

                path = _getenv("PATH");
                if (path != NULL)
                {
                        printf("%s\n", path);
                        printf("PATH is set.\n");
                }
                else
                {
                        printf("PATH is not set.\n");
                }
                token_path = strtok(path, delim_path);
                pid1 = fork();
                if (pid1 == -1)
                {
                        perror("child not born in path\n");
                        exit(1);
                }
                else if (pid1 == 0)
                {
                        printf("am child");
                        while (token_path)
                        {
                                toks_path = malloc((strlen(token_path) + _strlen(argv[0]))+ 2);
                                _strcpy(toks_path, token_path);
                                _strcat(toks_path, "/");
                                _strcat(toks_path, argv[0]);
                                printf("%s1", toks_path);
                                if (access(toks_path, X_OK) == 0)
                                {
                                        /*printf("%s", toks_path);*/
                                        execve(toks_path, argv, environ);
                                        perror("execve error for token,path\n");
                                        exit(1);
                                }
                                free(toks_path);
                                token_path = strtok(NULL, delim_path);
                        }
                }
                else
                {
                        wait(NULL);
                }
                /*free(path);
                free(lineptr);
                free(toks);*/
                printf("am the father\n");
        }
        free(path);
        free(lineptr);
        free(toks);
        return (0);
}

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





#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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

        for (i = 0; environ[i] != NULL; i++)
        {
                for (j = 0; environ[i][j] != '\0'; j++)
                {
                        if (environ[i][j] == '=')
                        {
                                break;
                        }
                }
                _slit_str(environ[i], part_a, part_b, delim);
                strcomm = strcom(part_a, name);

                if (strcomm == 0)
                {
                        break;
                }
        }
        free(part_a);
        return (part_b);
}



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
