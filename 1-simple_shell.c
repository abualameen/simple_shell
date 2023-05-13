#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
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
        char *token;
        const char *delim;
        int j = 0;
        int t, count;
        extern char **environ;
        char *toks;
        pid_t pid;

        delim = " \n";
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
                token = strtok(lineptr, delim);
                while (token)
                {
                        argv[j] = _strcpy(toks, token);
                        token = strtok(NULL, delim);
                        j++;
                }
                argv[j] = NULL;
                pid = fork();
                if (pid == -1)
                {
                        perror("child not born\n");
                        exit(1);
                }
                else if (pid == 0)
                {
                        t = execve(argv[0], argv, environ);
                        perror("execve error\n");
                        exit(1);
                }
                else
                {
                        wait(NULL);
                }
                free(lineptr);
                free(toks);
                printf("am the father\n");
        }
        return (0);
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
