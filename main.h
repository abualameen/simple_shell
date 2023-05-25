#ifndef _FILE_NAME_H_
#define _FILE_NAME_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_strcpy(char *dest, char *src);
int execution(char *cpy);
int checkstat(char *command);
void forknow(char *argument, char **arguments);
char *pathfinder(char **ptr, char *storage, char *command);
char *_getenv(const char *name);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src, char *newstr);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _getchar(void);

extern char **environ;

#endif
